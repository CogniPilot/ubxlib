/*
 * FreeRTOS Kernel V10.2.1
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * this is a template configuration files
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * These parameters and more are described within the 'configuration' section of the
 * FreeRTOS API documentation available on the FreeRTOS.org web site.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

/* Ensure stdint is only used by the compiler, and not the assembler. */
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
#include <stdint.h>
extern uint32_t SystemCoreClock;
#endif

/*------------- CMSIS-RTOS V2 specific defines -----------*/
/* When using CMSIS-RTOSv2 set configSUPPORT_STATIC_ALLOCATION to 1
 * is mandatory to avoid compile errors.
 * CMSIS-RTOS V2 implmentation requires the following defines
 *
#define configSUPPORT_STATIC_ALLOCATION          1   <-- cmsis_os threads are created using xTaskCreateStatic() API
#define configMAX_PRIORITIES                    (56) <-- Priority range in CMSIS-RTOS V2 is [0 .. 55]
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0    <-- when set to 1, configMAX_PRIORITIES can't be more than 32 which is not suitable for the new CMSIS-RTOS v2 priority range
*/

/* the CMSIS-RTOS V2 FreeRTOS wrapper is dependent on the heap implementation used
 * by the application thus the correct define need to be enabled from the list
 * below
 *
//define USE_FreeRTOS_HEAP_1
//define USE_FreeRTOS_HEAP_2
//define USE_FreeRTOS_HEAP_3
//define USE_FreeRTOS_HEAP_4
//define USE_FreeRTOS_HEAP_5
*/
#define USE_FreeRTOS_HEAP_4

#define configUSE_PREEMPTION              1
#define configUSE_IDLE_HOOK               0
#define configUSE_TICK_HOOK               0
#define configUSE_TICKLESS_IDLE           0
// If you change this you must change U_CFG_OS_PRIORITY_MAX
// in u_cfg_os_platform_specific.h to match.
#ifdef CMSIS_V2
# define configMAX_PRIORITIES             (56)
# define configSUPPORT_STATIC_ALLOCATION   1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION  0
#else
# define configMAX_PRIORITIES             (15)
# define configSUPPORT_STATIC_ALLOCATION   0
#endif
#define configCPU_CLOCK_HZ                (SystemCoreClock)
#define configTICK_RATE_HZ                ((TickType_t) 1000)
#define configMINIMAL_STACK_SIZE          ((uint16_t) 128)
#define configTOTAL_HEAP_SIZE             ((size_t) (16 * 1024))
#define configMAX_TASK_NAME_LEN           (16)
#define configUSE_TRACE_FACILITY          1
#define configUSE_16_BIT_TICKS            0
#define configIDLE_SHOULD_YIELD           1
#define configUSE_MUTEXES                 1
#define configQUEUE_REGISTRY_SIZE         8
#define configCHECK_FOR_STACK_OVERFLOW    1
#define configUSE_RECURSIVE_MUTEXES       1
#define configUSE_MALLOC_FAILED_HOOK      1
#define configUSE_APPLICATION_TASK_TAG    0
#define configUSE_COUNTING_SEMAPHORES     1
#define configGENERATE_RUN_TIME_STATS     0
#define configRECORD_STACK_HIGH_ADDRESS   1
/*  See http://www.nadler.com/embedded/newlibAndFreeRTOS.html */
#define configUSE_NEWLIB_REENTRANT        1

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES           0
#define configMAX_CO_ROUTINE_PRIORITIES (2)

/* Software timer definitions. */
#define configUSE_TIMERS             1
#define configTIMER_TASK_PRIORITY    (2)
#define configTIMER_QUEUE_LENGTH     10
#define configTIMER_TASK_STACK_DEPTH (configMINIMAL_STACK_SIZE * 2)

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet            1
#define INCLUDE_uxTaskPriorityGet           1
#define INCLUDE_vTaskDelete                 1
#define INCLUDE_vTaskCleanUpResources       1
#define INCLUDE_vTaskSuspend                1
#define INCLUDE_vTaskDelay                  1
#define INCLUDE_xTaskGetSchedulerState      1
#define INCLUDE_uxTaskGetStackHighWaterMark 1
#ifdef CMSIS_V2
# define USE_CUSTOM_SYSTICK_HANDLER_IMPLEMENTATION 1
# define INCLUDE_vTaskDelayUntil            1
# define INCLUDE_xSemaphoreGetMutexHolder   1
# define INCLUDE_xTaskGetCurrentTaskHandle  1
# define INCLUDE_eTaskGetState              1
# define INCLUDE_xTimerPendFunctionCall     1
#else
# define INCLUDE_vTaskDelayUntil            0
#endif

/* Cortex-M specific definitions. */
#ifdef __NVIC_PRIO_BITS
/* __BVIC_PRIO_BITS will be specified when CMSIS is being used. */
#define configPRIO_BITS         __NVIC_PRIO_BITS
#else
#define configPRIO_BITS         4        /* 15 priority levels */
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority"
function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY   0xf

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY   ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY  ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Normal assert() semantics without relying on the provision of an assert.h
header file. */
void uAssertFailed(const char *pFileStr, int32_t line);
#define configASSERT( x ) if( ( x ) == 0 ) { taskDISABLE_INTERRUPTS(); uAssertFailed(__FILE__, __LINE__); }

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
   standard names. */
#define vPortSVCHandler    SVC_Handler
#define xPortPendSVHandler PendSV_Handler

/* IMPORTANT: FreeRTOS is using the SysTick as internal time base, thus make sure the system and peripherials are
              using a different time base (TIM based for example).
 */
/* #define xPortSysTickHandler SysTick_Handler */

#ifdef U_DEBUG_UTILS_DUMP_THREADS
/* When ubxlib dump threads are enabled we need an FreeRTOS addition
 * to be able to get the stack for each thread
 */
#define configINCLUDE_FREERTOS_TASK_C_ADDITIONS_H        1
/* Defines for needed for the FreeRTOS addition above */
#define CONFIG_FREERTOS_ENABLE_TASK_SNAPSHOT             1
#define CONFIG_FREERTOS_SMP                              1
#define portVALID_TCB_MEM(x)                             1

/* This is needed in order to keep compiler happy */
#define FREERTOS_TASKS_C_ADDITIONS_INIT()
#endif

#endif /* FREERTOS_CONFIG_H */

