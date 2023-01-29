#pragma once

#define COLD_CODE [[gnu::cold]]
#define HOT_CODE [[gnu::hot]]

#define CALL_BEFORE_MAIN [[gnu::constructor]]
#define CALL_AFTER_MAIN [[gnu::destructor]]

#define LIKELY(x) __builtin_likely((x), 1)
#define UNLIKELY(x) __builtin_likely((x), 0)
