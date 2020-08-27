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

/* Only bring in #includes specifically related to the test framework */

#include "unity.h"

/** @file
 * @brief Porting layer and configuration items passed in at application
 * level when executing tests on the ESP32 platform.
 */

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS: UNITY RELATED
 * -------------------------------------------------------------- */

/** Macro to wrap a test assertion and map it to unity.
 */
#define U_PORT_TEST_ASSERT(condition) TEST_ASSERT(condition)

/** Macro to wrap the definition of a test function and
 * map it to unity.
 */
#define U_PORT_TEST_FUNCTION(group, name) TEST_CASE(name, \
                                                    group)

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS: OS RELATED
 * -------------------------------------------------------------- */

/** The stack size to use for the test task created during OS testing.
 */
#define U_CFG_TEST_OS_TASK_STACK_SIZE_BYTES 1536

/** The task priority to use for the task created during OS
 * testing: make sure that the priority of the task RUNNING
 * the tests is lower than this.  In FreeRTOS, as used on this
 * platform, low numbers indicate lower priority.
 */
#define U_CFG_TEST_OS_TASK_PRIORITY (U_CFG_OS_PRIORITY_MIN + 5)

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS: HW RELATED
 * -------------------------------------------------------------- */

/** Pin A for GPIO testing: will be used as an output and
 * must be connected to pin B via a 1k resistor.
 */
#ifndef U_CFG_TEST_PIN_A
# define U_CFG_TEST_PIN_A         33
#endif

/** Pin B for GPIO testing: will be used as both an input and
 * and open drain output and must be connected both to pin A via
 * a 1k resistor and directly to pin C.
 */
#ifndef U_CFG_TEST_PIN_B
# define U_CFG_TEST_PIN_B         32
#endif

/** Pin C for GPIO testing: must be connected to pin B,
 * will be used as an input only.
 */
#ifndef U_CFG_TEST_PIN_C
# define U_CFG_TEST_PIN_C         35
#endif

/** UART HW block for UART driver loopback testing.
 */
#ifndef U_CFG_TEST_UART_0
# define U_CFG_TEST_UART_0          2
#endif

/** UART HW block for UART driver loopback testing where
 * two UARTs are employed.
 */
#ifndef U_CFG_TEST_UART_1
# define U_CFG_TEST_UART_1          -1
#endif

/** The baud rate to test the UART at.
 */
#ifndef U_CFG_TEST_BAUD_RATE
# define U_CFG_TEST_BAUD_RATE 115200
#endif

/** The length of UART buffer to use.
 */
#ifndef U_CFG_TEST_UART_BUFFER_LENGTH_BYTES
# define U_CFG_TEST_UART_BUFFER_LENGTH_BYTES 1024
#endif

/** Tx pin for UART testing: should be connected either to the
 * Rx UART pin or to U_CFG_TEST_PIN_UART_1_RXD if that is
 * not -1.
 */
#ifndef U_CFG_TEST_PIN_UART_0_TXD
# define U_CFG_TEST_PIN_UART_0_TXD   13
#endif

/** Rx pin for UART testing: should be connected either to the
 * Tx UART pin or to U_CFG_TEST_PIN_UART_1_TXD if that is
 * not -1.
 */
#ifndef U_CFG_TEST_PIN_UART_0_RXD
# define U_CFG_TEST_PIN_UART_0_RXD   14
#endif

/** CTS pin for UART testing: should be connected either to the
 * RTS UART pin or to U_CFG_TEST_PIN_UART_1_RTS if that is
 * not -1.
 */
#ifndef U_CFG_TEST_PIN_UART_0_CTS
# define U_CFG_TEST_PIN_UART_0_CTS   26
#endif

/** RTS pin for UART testing: should be connected connected either to the
 * CTS UART pin or to U_CFG_TEST_PIN_UART_1_CTS if that is
 * not -1.
 */
#ifndef U_CFG_TEST_PIN_UART_0_RTS
# define U_CFG_TEST_PIN_UART_0_RTS   27
#endif

/** Tx pin for dual-UART testing: if present should be connected to
 * U_CFG_TEST_PIN_UART_0_RXD.
 */
#ifndef U_CFG_TEST_PIN_UART_1_TXD
# define U_CFG_TEST_PIN_UART_1_TXD   -1
#endif

/** Rx pin for dual-UART testing: if present should be connected to
 * U_CFG_TEST_PIN_UART_0_TXD.
 */
#ifndef U_CFG_TEST_PIN_UART_1_RXD
# define U_CFG_TEST_PIN_UART_1_RXD   -1
#endif

/** CTS pin for dual-UART testing: if present should be connected to
 * U_CFG_TEST_PIN_UART_0_RTS.
 */
#ifndef U_CFG_TEST_PIN_UART_1_CTS
# define U_CFG_TEST_PIN_UART_1_CTS   -1
#endif

/** RTS pin for UART testing: if present should be connected to
 * U_CFG_TEST_PIN_UART_0_CTS.
 */
#ifndef U_CFG_TEST_PIN_UART_1_RTS
# define U_CFG_TEST_PIN_UART_1_RTS   -1
#endif

#endif // _U_CFG_TEST_PLATFORM_SPECIFIC_H_

// End of file