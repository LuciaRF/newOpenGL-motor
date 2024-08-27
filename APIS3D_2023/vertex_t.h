#pragma once
#define GLAD_ONLY_HEADERS
#include "common.h"

typedef struct vertex_t {
    glm::vec4 pos;
    glm::vec4 color;
    glm::vec2 vText;
}vertex_t;