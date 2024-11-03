#!/usr/bin/env python 

import os
import sys

"""
This is a utilitys script for charlie2D, meant for generating files from templates
"""

HELP_DISPLAY = """This is a utilitys script for charlie2D, meant for generating files from templates

new_creater [name]
new_component [name]
"""

SRC_DIRECTORY = os.path.join(os.path.dirname(os.path.realpath(__file__)), "src")
NEW_COMPONENT_TEMPLATE = """#pragma once

#include "Charlie2D.hpp"
#include "config.h"

class {} : public Component {{
public:
  void start() override {{
  }}

  void update(float deltaTime) override {{
  }}
}};
"""
NEW_CREATER_TEMPLATE = """#pragma once

#include "Charlie2D.hpp"
#include "config.h"

Entity* create{}() {{
    Entity* entity = GameManager::createEntity("{}");

    
    return entity;
}}
"""


def create_component_file(name: str):
    name = name.replace(' ', '')

    components_path = os.path.join(SRC_DIRECTORY, "components")
    if not os.path.exists(components_path):
        os.makedirs(components_path)

    with open(os.path.join(components_path, f"{name}_component.hpp"), "w+") as f:
        f.write(NEW_COMPONENT_TEMPLATE.format(name))

def create_creater_file(name: str):
    name = name.replace(' ', '')

    creaters_path = os.path.join(SRC_DIRECTORY, "creaters")
    if not os.path.exists(creaters_path):
        os.makedirs(creaters_path)

    with open(os.path.join(creaters_path, f"{name}_creater.hpp"), "w+") as f:
        f.write(NEW_CREATER_TEMPLATE.format(name.capitalize(), name))

def main():
    if (sys.argv[1] == 'new_creater'):
        create_creater_file(sys.argv[2])
    elif (sys.argv[1] == 'new_component'):
        create_component_file(sys.argv[2])
    elif (sys.argv[1].lower() == 'help'):
        print(HELP_DISPLAY)

if __name__ == '__main__':
    main()

