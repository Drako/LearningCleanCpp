#pragma once

#ifndef LINKED_LIST_HXX
#define LINKED_LIST_HXX

#include <cstddef>

namespace exercise {
    /**
     * A singly linked list.
     */
    template <typename ValueType>
    struct linked_list {
        /**
         * Add the given [value] to the list.
         */
        inline void push(ValueType const& value) {
            // TODO: implement
        }

        /**
         * Remove the most recent value from the list and return it.
         * 
         * @throws std::out_of_range if the list is empty.
         */
        inline ValueType pop() {
            // TODO: implement
            return {};
        }

        /**
         * Query whether the list is empty.
         */
        inline bool empty() const {
            // TODO: implement
            return false;
        }

        /**
         * Query the number of values in the list.
         */
        inline std::size_t length() const {
            // TODO: implement
            return 0u;
        }

        /**
         * Iterate over all values in the list and do something with them.
         */
        template <typename Handler>
        inline void for_each(Handler && handler) const {
            // TODO: implement
        }
    };
}

#endif // LINKED_LIST_HXX
