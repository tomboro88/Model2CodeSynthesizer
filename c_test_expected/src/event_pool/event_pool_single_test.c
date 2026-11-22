/**
 * @file event_pool_single_test.c
 *
 * @brief Source code of the event_pool_single test group.
 * @details Performs tests of the event_pool module managing a single event
 * type (a single fifo queue), as generated for classifiers handling only one
 * event.
 * @author tomboro88
 * @date   22 november 2026
 * @copyright (c) 2026 tomboro88.
 * @license SPDX-License-Identifier: EPL-2.0
 * @project github.com/tomboro88/Model2CodeSynthesizer
 */

#include <unity_fixture.h>
#include <event_pool.h>

/**
 * @brief The number of event types handled by the tested pool.
 */
#define SINGLE_EVENT_TYPE_COUNT 1u

/**
 * @brief The only event type handled by the tested pool.
 */
#define SINGLE_EVENT_TYPE 0u

/**
 * @brief The capacity of the only event queue.
 */
#define SINGLE_EVENT_CNT 3u

TEST_GROUP(event_pool_single);

static event_pool_t      event_pool = {0};

static event_pool_fifo_t fifo_pool[SINGLE_EVENT_TYPE_COUNT];

static event_pool_size_t single_next_events[SINGLE_EVENT_CNT];

static const fifo_size_t single_fifo_sizes[SINGLE_EVENT_TYPE_COUNT] =
        {
                SINGLE_EVENT_CNT
        };

/**
 * @brief The result of the event pool initialization done in the setup.
 */
static bool b_is_initialized = false;

/*======================================TESTS=================================*/

/**
 * @brief Verifies that the first event in the pool is located at the given
 * index of the only queue.
 */
static void
event_pool_single_assert_first(fifo_size_t const expected_index)
{
    event_pool_locator_t locator = {.event_type = SINGLE_EVENT_TYPE_COUNT,
                                    .event_index = 0u};

    TEST_ASSERT_TRUE(event_pool_get_first_head(&event_pool, &locator));
    TEST_ASSERT_EQUAL_UINT(SINGLE_EVENT_TYPE, locator.event_type);
    TEST_ASSERT_EQUAL_UINT(expected_index, locator.event_index);
}

/**
 * @brief Verifies that the pool is empty.
 */
static void
event_pool_single_assert_empty(void)
{
    event_pool_locator_t locator = {.event_type = SINGLE_EVENT_TYPE_COUNT,
                                    .event_index = 0u};

    TEST_ASSERT_FALSE(event_pool_get_first_head(&event_pool, &locator));
    TEST_ASSERT_FALSE(event_pool_dequeue(&event_pool));
}

TEST_SETUP(event_pool_single)
{
    event_pool = (event_pool_t) {0};

    fifo_initialize(&fifo_pool[0].fifo, single_fifo_sizes[0], 0u, 0u);
    fifo_pool[0].p_next_events = single_next_events;

    b_is_initialized = event_pool_initialize(&event_pool, fifo_pool,
                                             single_fifo_sizes,
                                             SINGLE_EVENT_TYPE_COUNT);
}

TEST_TEAR_DOWN(event_pool_single)
{

}

TEST(event_pool_single, init_ok)
{
    TEST_ASSERT_TRUE(b_is_initialized);
    event_pool_single_assert_empty();
}

TEST(event_pool_single, enqueue_invalid_event_fail)
{
    TEST_ASSERT_FALSE(event_pool_enqueue(&event_pool,
                                         SINGLE_EVENT_TYPE_COUNT));
    event_pool_single_assert_empty();
}

TEST(event_pool_single, enqueue_until_full)
{
    for(fifo_size_t i = 0u; i < SINGLE_EVENT_CNT; ++i)
    {
        TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, SINGLE_EVENT_TYPE));
    }

    TEST_ASSERT_FALSE(event_pool_enqueue(&event_pool, SINGLE_EVENT_TYPE));
}

TEST(event_pool_single, get_first_after_enqueue)
{
    TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, SINGLE_EVENT_TYPE));
    event_pool_single_assert_first(0u);
}

TEST(event_pool_single, dequeue_in_order_until_empty)
{
    for(fifo_size_t i = 0u; i < SINGLE_EVENT_CNT; ++i)
    {
        TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, SINGLE_EVENT_TYPE));
    }

    for(fifo_size_t i = 0u; i < SINGLE_EVENT_CNT; ++i)
    {
        event_pool_single_assert_first(i);
        TEST_ASSERT_TRUE(event_pool_dequeue(&event_pool));
    }

    event_pool_single_assert_empty();
}

TEST(event_pool_single, reuse_after_empty)
{
    TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, SINGLE_EVENT_TYPE));
    TEST_ASSERT_TRUE(event_pool_dequeue(&event_pool));
    event_pool_single_assert_empty();

    TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, SINGLE_EVENT_TYPE));
    event_pool_single_assert_first(1u);
    TEST_ASSERT_TRUE(event_pool_dequeue(&event_pool));
    event_pool_single_assert_empty();
}

TEST(event_pool_single, interleaved_with_index_wrap_around)
{
    fifo_size_t expected_head = 0u;

    /* Keep two events in the pool while the indexes pass the end of the
     * queue several times.*/
    TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, SINGLE_EVENT_TYPE));
    TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, SINGLE_EVENT_TYPE));

    for(unsigned int i = 0u; i < (4u * SINGLE_EVENT_CNT); ++i)
    {
        TEST_ASSERT_TRUE(event_pool_enqueue(&event_pool, SINGLE_EVENT_TYPE));
        event_pool_single_assert_first(expected_head);
        TEST_ASSERT_TRUE(event_pool_dequeue(&event_pool));
        expected_head = (expected_head + 1u) % SINGLE_EVENT_CNT;
    }

    event_pool_single_assert_first(expected_head);
    TEST_ASSERT_TRUE(event_pool_dequeue(&event_pool));
    expected_head = (expected_head + 1u) % SINGLE_EVENT_CNT;
    event_pool_single_assert_first(expected_head);
    TEST_ASSERT_TRUE(event_pool_dequeue(&event_pool));
    event_pool_single_assert_empty();
}

TEST_GROUP_RUNNER(event_pool_single)
{
    RUN_TEST_CASE(event_pool_single, init_ok);
    RUN_TEST_CASE(event_pool_single, enqueue_invalid_event_fail);
    RUN_TEST_CASE(event_pool_single, enqueue_until_full);
    RUN_TEST_CASE(event_pool_single, get_first_after_enqueue);
    RUN_TEST_CASE(event_pool_single, dequeue_in_order_until_empty);
    RUN_TEST_CASE(event_pool_single, reuse_after_empty);
    RUN_TEST_CASE(event_pool_single, interleaved_with_index_wrap_around);
}

/*** end of file ***/
