/**
 * @file 
 * 
 * @note Automatically generated code by Model2CodeSynthesizer
 * (github.com/tomboro88/Model2CodeSynthesizer).
 */

#ifndef SAFESM_H
#define SAFESM_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include "../umltest.h"
#    include <plogger.h>
#    include <sm.h>
#    include <event_pool.h>
#    include <stddef.h>
#    include <stdbool.h>
#    include <stdint.h>
//Start of user code includes bottom
//End of user code

    /**
     * @brief The type representing the safesm_sm1_s struct.
     */
    typedef struct safesm_sm1_s \
            safesm_sm1_t;

    /**
     * @brief The size of the event queue storing the a events.
     */
#    define SAFESM_SM1_A_CNT 2u

    /**
     * @brief The enumeration of all substates of Region1 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region1 Region of sm1
         * StateMachine.
         */
        SAFESM_SM1_INITIAL1,
        /**
         */
        SAFESM_SM1_SAFESTATE,
        /**
         */
        SAFESM_SM1_STATE1,
        /**
         */
        SAFESM_SM1_STATE3,
        /**
         * @brief The number of all substates of Region1 Region of sm1
         * StateMachine.
         */
        SAFESM_SM1_REGION1_SIZE
    }safesm_sm1_region1_t;
    
    /**
     * @brief The enumeration of all substates of Region2 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region2 Region of sm1
         * StateMachine.
         */
        SAFESM_SM1_INITIAL2,
        /**
         */
        SAFESM_SM1_STATE2,
        /**
         * @brief The number of all substates of Region2 Region of sm1
         * StateMachine.
         */
        SAFESM_SM1_REGION2_SIZE
    }safesm_sm1_region2_t;
    
    /**
     * @brief The enumeration of all substates of Region4 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region4 Region of sm1
         * StateMachine.
         */
        SAFESM_SM1_INITIAL3,
        /**
         */
        SAFESM_SM1_STATE5,
        /**
         * @brief The number of all substates of Region4 Region of sm1
         * StateMachine.
         */
        SAFESM_SM1_REGION4_SIZE
    }safesm_sm1_region4_t;
    
    /**
     * @brief The enumeration of all substates of Region3 Region of sm1
     * StateMachine.
     */
    typedef enum{
        /**
         * @brief The default substate of the Region3 Region of sm1
         * StateMachine.
         */
        SAFESM_SM1_REGION3_INL,
        /**
         */
        SAFESM_SM1_STATE4,
        /**
         * @brief The number of all substates of Region3 Region of sm1
         * StateMachine.
         */
        SAFESM_SM1_REGION3_SIZE
    }safesm_sm1_region3_t;
    
    /**
     * @brief The enumeration of all events handled by sm1 Class.
     */
    enum safesm_sm1_evtype
    {
        /**
         */
        SAFESM_SM1_A,
        /**
         * @brief The number of all events handled by sm1 Class.
         */
        SAFESM_SM1_EVENT_COUNT
    };
    
    /**
     * @brief The type used to store the parameters passed to the a call event.
     */
    typedef struct{
        /**
         * Parameter used for checking of proper operation of event pool with
         * only one event type.
         */
        uint16_t                        u16_param;
    }safesm_sm1_a_t;
    
    /**
     * @brief The type used to store the event pool of all events accepted by
     * the sm1 class.
     */
    typedef struct {
        /**
         * @brief The main event pool manager object in the sm1 class.
         */
        event_pool_t                    manager;
        /**
         * @brief The array of fifo objects, one for each accepted event type.
         * @details The objects are referenced and managed by the event_pool
         * object.
         */
        event_pool_fifo_t               fifo_pool[SAFESM_SM1_EVENT_COUNT];
        /**
         * @brief The array of the events that follow any a event in the event
         * pool sequence.
         * @details It is referenced by the fifo_pool[SAFESM_SM1_A] object.
         */
        event_pool_size_t               a_next_events[SAFESM_SM1_A_CNT];
        /**
         * @brief The array of the arguments passed to the corresponding a event
         * in the event pool sequence.
         */
        safesm_sm1_a_t                  a_args[SAFESM_SM1_A_CNT];
        /**
         * @brief The marker that stores the processing status of the event at
         * the 'first' position.
         * @details It is used to prevent processing of the same event multiple
         * times, and from removing unprocessed events. Moreover it can be used
         * to handle event deferring.
         */
        sm_event_status_t               event_proc_status;
        /**
         * @brief Stores the location of the event that is currently being
         * processed.
         */
        event_pool_locator_t            fetched_event;
    }safesm_sm1_event_pool_t;
    
    /**
     */
    struct safesm_sm1_s
    {
        /**
         */
        safesm_sm1_region1_t            region1;
        /**
         */
        safesm_sm1_region2_t            region2;
        /**
         */
        safesm_sm1_region4_t            region4;
        /**
         */
        safesm_sm1_region3_t            region3;
        /**
         * @brief The event pool object managing all events corresponding to the
         * sm1 class.
         */
        safesm_sm1_event_pool_t         event_pool;
        /**
         */
        plogger_logger_t*               p_logger;
    };

    bool safesm_sm1_a(safesm_sm1_t* const p_obj, uint16_t const u16_param);
    bool safesm_sm1_init(safesm_sm1_t* const p_obj,\
                         plogger_logger_t* const p_logger_obj);
    bool safesm_sm1_fetch_event(safesm_sm1_t* const p_obj);
    bool safesm_sm1_dispatch_event(safesm_sm1_t* const p_obj);
    bool safesm_sm1_release_event(safesm_sm1_t* const p_obj);

#ifdef  __cplusplus
}
#endif

#endif  /* SAFESM_H */

/*** end of file ***/
