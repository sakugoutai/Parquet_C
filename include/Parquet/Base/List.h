#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "Parquet/Base/Any.h"
#include "Parquet/Base/Error.h"
#include "Parquet/Base/Memory.h"
#include "Parquet/Base/String.h"

typedef struct List_t {
	uint32_t _Size;
	uint32_t _Length;
	any **_Item;

	void (* Add)(struct List_t *, any *item);

	uint32_t (* GetLength)(struct List_t *);
	any *(* Get)(struct List_t *, const uint32_t idx);

	bool (* IsEmpty)(struct List_t *);

	void (* Delete)(struct List_t *);
} List_t;

typedef struct {
	uint32_t _ALLOCATION_BLOCK_SIZE;

	List_t *(* New)();
	void (* Delete)(List_t *);

	void (* Add)(List_t *, any *item);

	uint32_t (* GetLength)(List_t *);
	any *(* Get)(List_t *, const uint32_t idx);

	bool (* IsEmpty)(List_t *);
} _List;

extern _List List;
