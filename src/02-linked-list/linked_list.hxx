#pragma once

#ifndef LINKED_LIST_HXX
#define LINKED_LIST_HXX

#include <memory>
#include <stdexcept>

namespace exercise {
    /**
     * A singly linked list.
     */
    template <typename ValueType>
    class linked_list {
        struct item {
            ValueType value;
            std::unique_ptr<item> next;

            item(ValueType const value, std::unique_ptr<item> next = {})
                : value{value}
                , next{std::move(next)}
            {}
        };

        std::unique_ptr<item> head;

    public:
        /**
         * Add the given [value] to the list.
         */
        inline void push(ValueType const& value) {
            head = std::make_unique<item>(value, std::move(head));
        }

        /**
         * Remove the most recent value from the list and return it.
         * 
         * @throws std::out_of_range if the list is empty.
         */
        inline ValueType pop() {
            if (empty()) {
                throw std::out_of_range{"Popping from empty list."};
            }
            auto const result = std::move(head->value);
            head = std::move(head->next);
            return result;
        }

        /**
         * Query whether the list is empty.
         */
        inline bool empty() const {
            return !head;
        }

        /**
         * Query the number of values in the list.
         */
        inline std::size_t length() const {
            std::size_t count{};
            for (
                item* p = head.get();
                p;
                p = p->next.get()
                ) {
                ++count;
            }
            return count;
        }

        /**
         * Iterate over all values in the list and do something with them.
         */
        template <typename Handler>
        inline void for_each(Handler && handler) const {
            for (item* p = head.get(); p; p = p->next.get()) {
                handler(p->value);
            }
        }
    };
}

#endif // LINKED_LIST_HXX
