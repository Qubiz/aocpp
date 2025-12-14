module;

#include <expected>

export module qubiz.status;

import qubiz.core;

export namespace qubiz {
    enum class error_code : u8 {
        /**
         * Operation completed successfully.
         */
        ok = 0,

        /**
         * Operation was explicitly cancelled, typically by the caller.
         */
        cancelled = 1,

        /**
         * Unknown error occurred; a catch-all for cases with no clearer category.
         */
        unknown = 2,

        /**
         * Client specified an invalid argument; request is malformed or out of range.
         */
        invalid_argument = 3,

        /**
         * Deadline expired before the operation could complete.
         */
        deadline_exceeded = 4,

        /**
         * Requested entity was not found.
         */
        not_found = 5,

        /**
         * Attempted to create an entity that already exists.
         */
        already_exists = 6,

        /**
         * Caller does not have permission to execute the specified operation.
         */
        permission_denied = 7,

        /**
         * Resource exhausted, e.g., out of memory or quota.
         */
        resource_exhausted = 8,

        /**
         * Operation rejected due to the system being in an invalid state.
         */
        failed_precondition = 9,

        /**
         * Operation aborted, typically due to concurrency conflicts.
         */
        aborted = 10,

        /**
         * Argument or operation is out of valid range.
         */
        out_of_range = 11,

        /**
         * Operation is not implemented or not supported.
         */
        unimplemented = 12,

        /**
         * Internal error; indicates an unexpected condition within the system.
         */
        internal = 13,

        /**
         * Service is currently unavailable; retrying may succeed.
         */
        unavailable = 14,

        /**
         * Unrecoverable data loss or corruption detected.
         */
        data_loss = 15,

        /**
         * Request lacks valid authentication credentials.
         */
        unauthenticated = 16,
    };

    /**
     * @brief Provides a null-terminated string representation of the given error code.
     *
     * @param e The error code to convert to a string.
     * @return Null-terminated string representation of the given error code.
     */
    [[nodiscard]] constexpr auto as_string(const error_code e) -> const char * {
        switch (e) {
            case error_code::ok:
                return "ok";
            case error_code::cancelled:
                return "cancelled";
            case error_code::unknown:
                return "unknown";
            case error_code::invalid_argument:
                return "invalid_argument";
            case error_code::deadline_exceeded:
                return "deadline_exceeded";
            case error_code::not_found:
                return "not_found";
            case error_code::already_exists:
                return "already_exists";
            case error_code::permission_denied:
                return "permission_denied";
            case error_code::resource_exhausted:
                return "resource_exhausted";
            case error_code::failed_precondition:
                return "failed_precondition";
            case error_code::aborted:
                return "aborted";
            case error_code::out_of_range:
                return "out_of_range";
            case error_code::unimplemented:
                return "unimplemented";
            case error_code::internal:
                return "internal";
            case error_code::unavailable:
                return "unavailable";
            case error_code::data_loss:
                return "data_loss";
            case error_code::unauthenticated:
                return "unauthenticated";
        }

        unreachable();
    }

    template<typename T>
    using Result = std::expected<T, error_code>;

    using Status = Result<void>;
}
