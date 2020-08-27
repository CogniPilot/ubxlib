/*
 * Copyright 2020 u-blox Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _U_CFG_TEST_PLATFORM_SPECIFIC_H_
#define _U_CFG_TEST_PLATFORM_SPECIFIC_H_

/* Only bring in #includes specifically related to the test framework. */

/** @file
 * @brief This header file contains dummy test configuration information
 * for Lint.
 */

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS
 * -------------------------------------------------------------- */

#define U_PORT_TEST_ASSERT(condition) U_PORT_UNITY_TEST_ASSERT(condition)
#define U_PORT_TEST_FUNCTION(name, group) U_PORT_UNITY_TEST_FUNCTION(name,  \
                                                                     group)
#define U_CFG_TEST_OS_TASK_STACK_SIZE_BYTES 1024
#define U_CFG_TEST_OS_TASK_PRIORITY (U_CFG_OS_PRIORITY_MIN + 5)

// Note: pins set to 0 rather than -1 in order to not
// disable any code that is conditional on them existing
#define U_CFG_TEST_PIN_A            0
#define U_CFG_TEST_PIN_B            0
#define U_CFG_TEST_PIN_C            0
#define U_CFG_TEST_UART_0           0
#define U_CFG_TEST_UART_1           0
#define U_CFG_TEST_BAUD_RATE      115200
#define U_CFG_TEST_UART_BUFFER_LENGTH_BYTES 0
#define U_CFG_TEST_PIN_UART_0_TXD   0
#define U_CFG_TEST_PIN_UART_0_RXD   0
#define U_CFG_TEST_PIN_UART_0_CTS   0
#define U_CFG_TEST_PIN_UART_0_RTS   0
#define U_CFG_TEST_PIN_UART_1_TXD   0
#define U_CFG_TEST_PIN_UART_1_RXD   0
#define U_CFG_TEST_PIN_UART_1_CTS   0
#define U_CFG_TEST_PIN_UART_1_RTS   0

#endif // _U_CFG_TEST_PLATFORM_SPECIFIC_H_

// End of file