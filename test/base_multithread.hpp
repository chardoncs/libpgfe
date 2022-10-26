/*
  libpgfe
  base_multithread.hpp

  Copyright (c) 2022 Charles Dong
*/

#include "test.h"

#include <cstring>
#include <queue>
#include <stdexcept>
#include <thread>

#include "../include/base-encoding.h"
#include "../include/base64.hpp"

using namespace chardon55::PGFE;

void __bm_encode(Base64 *encoder, const char *input_str, const char *expected) {
    auto str = encoder->encode(input_str);
    if (str != expected) {
        throw std::exception();
    }
}

void __bm_decode(Base64 *decoder, const char *input_str, const char *expected) {
    auto sd = decoder->decode(input_str);
    auto str = sd.to_str();
    if (str != expected) {
        throw std::exception();
    }
}

void base_multithread1(ARGS) {
    static const char input1[] = "You chose this path!";
    static const char input2[] = "Now I have a surprise for you!";
    static const char input3[] = "Deploying surprise (multithreading) in five, four...";

    int i;
    static const int times = 50;

    char expected1[400], expected2[400], expected3[400];

    pgfe_encode_base64((pgfe_encode_t *)input1, strlen(input1), expected1);
    pgfe_encode_base64((pgfe_encode_t *)input2, strlen(input2), expected2);
    pgfe_encode_base64((pgfe_encode_t *)input3, strlen(input3), expected3);

    Base64 base_shared;

    std::queue<std::thread *> thread_queue;

    for (i = 0; i < times; i++) {
        thread_queue.push(new std::thread(__bm_encode, &base_shared, input1, expected1));
        thread_queue.push(new std::thread(__bm_encode, &base_shared, input2, expected2));
        thread_queue.push(new std::thread(__bm_encode, &base_shared, input3, expected3));
        thread_queue.push(new std::thread(__bm_decode, &base_shared, expected1, input1));
        thread_queue.push(new std::thread(__bm_decode, &base_shared, expected2, input2));
        thread_queue.push(new std::thread(__bm_decode, &base_shared, expected3, input3));
    }

    while (!thread_queue.empty()) {
        auto th = thread_queue.front();
        thread_queue.pop();
        th->join();
        delete th;
    }
}