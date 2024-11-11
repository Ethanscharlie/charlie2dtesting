#include "Charlie2D.hpp"
#include <cstdio>
#include <format>
#include <iostream>

#include "Component.hpp"
#include "GameManager.hpp"
#include "Math.hpp"
#include "SDL_render.h"
#include "config.h"

/*
 * Some useful code snips
 *
 * LDTK::loadJson("res/ldtk.ldtk");
 * LDTK::onLoadLevel = [](auto entities) {
 *   for (Entity *entity : entities) {
 *     if (entity->tag == "Player")
 *      std::cout << "Player\n";
 *   }
 * };
 * LDTK::loadLevel("65ba8250-25d0-11ef-b0ef-03acbc99fa7b");
 */

class TestComponent : public Component {
public:
  TestComponent(Entity &entity) : Component(entity) {}
  void update() override {}
  void onDestroy() override {}

};

int main(int, char **) {
  GameManager::init();

  // Entity
  {
    Entity &entity = GameManager::createEntity("");
    entity.addComponent<Sprite>();
    entity.getComponent<Sprite>().standardUpdate =
        false; // Access data from added component

    entity.remove<Sprite>();
    if (entity.checkComponent<Sprite>()) {
      printf("Component removal failed\n");
    }
  }

  // Component
  {
    Entity &entity = GameManager::createEntity("");
    TestComponent &test = entity.addComponent<TestComponent>();
  }

  // Game Manager
  {
    GameManager::destroyAll();

    GameManager::createEntity("Me");
    GameManager::createEntity("Me");
    GameManager::createEntity("Me");
    GameManager::createEntity("Me2");
    GameManager::createEntity("Me2");
    GameManager::createEntity("Me2");

    GameManager::getEntities("Me");
    GameManager::getComponents<Sprite>();

    if (GameManager::getEntities().size() < 6) {
      printf("Get all object returned the wrong amount of objects\n");
    }

    GameManager::destroyAll();
  }

  // Vector2f
  {
    Vector2f v1(1.0f, 2.0f);
    Vector2f v2(3.0f, 4.0f);
    Vector2f v3;

    // Test assignment operator
    v3 = v1;
    assert(v3.x == 1.0f && v3.y == 2.0f);

    // Test += operator
    v1 += v2;
    assert(v1.x == 4.0f && v1.y == 6.0f);

    // Reset v1 for further tests
    v1 = Vector2f(1.0f, 2.0f);

    // Test + operator
    v3 = v1 + v2;
    assert(v3.x == 4.0f && v3.y == 6.0f);

    // Test - operator
    v3 = v1 - v2;
    assert(v3.x == -2.0f && v3.y == -2.0f);

    // Test * operator
    v3 = v1 * v2;
    assert(v3.x == 3.0f && v3.y == 8.0f);

    // Test / operator
    v3 = v1 / v2;
    assert(v3.x == 1.0f / 3.0f && v3.y == 2.0f / 4.0f);

    // Test scalar operations
    v3 = v1 + 2.0f;
    assert(v3.x == 3.0f && v3.y == 4.0f);

    v3 = v1 - 1.0f;
    assert(v3.x == 0.0f && v3.y == 1.0f);

    v3 = v1 * 2.0f;
    assert(v3.x == 2.0f && v3.y == 4.0f);

    v3 = v1 / 2.0f;
    assert(v3.x == 0.5f && v3.y == 1.0f);
    //
    // Test comparison operators
    Vector2f v4(1.0f, 2.0f);
    assert(v1 == v4);

    assert(v1 != v2);

    // Test length function
    assert(v1.length() == std::sqrt(1.0f * 1.0f + 2.0f * 2.0f));
  }

  // Box
  {}

  // Math
  {
    // Vector2f getLogcialPosition(Vector2f screenPos);
    // Vector2f getScreenPosition(Vector2f logicalPos);
    // Vector2f getImGuiPosition(Vector2f pos);
    // std::string getTypeNameWithoutNumbers(std::type_index typeIndex);
    // Box getRenderBox(Box box, EntityRenderPositionType renderPositionType =
    //                               EntityRenderPositionType::World);
    // Box getRenderBox(Entity * entity);

    float randomFloat = randFloat(0, 100);
    if (randomFloat < 0 || randomFloat > 100) {
      printf("Random number range is fucked\n");
    }

    int list[] = {1, 2, 3, 4, 5};
    int randomElement = getRandomElement(list);

    float f = 1.24124231453255;
    std::cout << std::format("This float should be rounded, {}\n",
                             floatToString(f));

    SDL_Rect rect = getLogicalRect();
    printf("Logical Rect of game: %d, %d, %d, %d\n", rect.x, rect.y, rect.w,
           rect.h);

    if (getTypeNameWithoutNumbers(typeid(Sprite)) != "Sprite") {
      printf("Type name without numbers doesn't work\n");
    }

    std::array<Uint8, 3> rgb = hexToRGB(0x874747);
    if (rgb[0] != 135 || rgb[1] != 71 || rgb[2] != 71) {
      printf("Hex to rgb is fucked\n");
    }
  }

  // Input Manager
  {
    // static int checkVertical();
    // static int checkHorizontal();
    // static Vector2f checkAxis();
    // static bool checkKeyHeld(SDL_Scancode scancode);
    // static Vector2f getMouseWorldPosition();
    // static Vector2f getMouseUIPosition();
    // static Vector2f getMouseScreenPosition();
    // static bool mouseHeld;
    // static bool leftMouseHeld;
    // static bool rightMouseHeld;
    // static float mouseScroll;
    // static bool keyEvents[NUM_KEYS];
    // static void onEvent(SDL_Event event);
  }

  // Image
  {
    Entity &entity = GameManager::createEntity("Sprite");
    entity.box.size = {400, 200};
    entity.addComponent<Sprite>().image = Image("res/PixilEthan.png");
    Image &image = entity.getComponent<Sprite>().image;
    image.flip = SDL_FLIP_HORIZONTAL;
    image.alpha = 100;
    image.color = {255, 0, 0};
    
    // Angle
    Angle angle;
    angle.rotate(90);
    entity.getComponent<Sprite>().angle = angle;
  }

  // Audio
  {
    Event::addEventListener("LeftMouseButtonDown", []() {
      Audio audio = Audio("res/sound/coldsnap.wav");
      audio.play();
    });
  }

  // Event
  {}

  // Controller Manager
  {}

  // Circle
  {
    Circle circle1 = Circle({0, 0}, 10);
    Circle circle2 = Circle({0, 1}, 10);
    Circle circle3 = Circle({0, 1000}, 10);

    if (!circle1.checkCollision(circle2)) {
      printf("Circles should have collided\n");
    }

    if (circle1.checkCollision(circle3)) {
      printf("Circles should not have collided\n");
    }
  }

  // Camera
  {}

  // END OF CORE TESTING

  // Alighnment.hpp
  {}

  // Animation.hpp
  {}

  // Button.hpp
  {}

  // ExtendedComponent.hpp
  {}

  // FadeTransition.hpp
  {}

  // JumpMan.hpp
  {}

  // LDTKEntity.hpp
  {}

  // Light.hpp
  {}

  // physicsBody.hpp
  {}

  // Scheduler.hpp
  {}

  // ShadowFilter.hpp
  {}

  // SolidBody.hpp
  {}

  // Sprite.hpp
  {}

  // Text.hpp
  {}

  // UISliceRenderer.hpp
  {}

  // LDTK
  // LDTK_EntityData.hpp
  {}

  // LDTK_EntityDefinition.hpp
  {}

  // LDTK_EntityInstance.hpp
  {}

  // LDTK_EntityLayer.hpp
  {}

  // LDTK_FieldInstance.hpp
  {}

  // LDTK_LayerDefinition.hpp
  {}

  // LDTK_Level.hpp
  {}

  // LDTK_Project.hpp
  {}

  // LDTK_TileLayer.hpp
  {}

  // LDTK_Tilemap.hpp
  {}

  // LDTK_Tileset.hpp
  {}

  // LDTK_World.hpp
  {}

  GameManager::doUpdateLoop();
  return 0;
}
