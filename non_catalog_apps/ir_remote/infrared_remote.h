#pragma once

#include <stdbool.h>

#include "infrared_remote_button.h"

#define IR_REMOTE_PATH EXT_PATH("infrared/remote")

typedef struct InfraredRemote InfraredRemote;

InfraredRemote* infrared_remote_alloc(void);
void infrared_remote_free(InfraredRemote* remote);
void infrared_remote_reset(InfraredRemote* remote);

void infrared_remote_set_name(InfraredRemote* remote, const char* name);
const char* infrared_remote_get_name(InfraredRemote* remote);

void infrared_remote_set_path(InfraredRemote* remote, const char* path);
const char* infrared_remote_get_path(InfraredRemote* remote);

size_t infrared_remote_get_button_count(InfraredRemote* remote);
InfraredRemoteButton* infrared_remote_get_button(InfraredRemote* remote, size_t index);
bool infrared_remote_find_button_by_name(InfraredRemote* remote, const char* name, size_t* index);

bool infrared_remote_add_button(InfraredRemote* remote, const char* name, InfraredSignal* signal);
bool infrared_remote_rename_button(InfraredRemote* remote, const char* new_name, size_t index);
bool infrared_remote_delete_button(InfraredRemote* remote, size_t index);

bool infrared_remote_store(InfraredRemote* remote);
bool infrared_remote_load(InfraredRemote* remote, FuriString* path);
bool infrared_remote_remove(InfraredRemote* remote);
