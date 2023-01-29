#include "EngineCore.h"
#include "EngineMantle.h"
#include "EngineGraphics.h"
#include <stdio.h>
#include <stdlib.h>

#include "Components/Position.h"

void t_move_run(List *cd, List *e)
{
    TASK_CD(cd, Position, cd_position);

    cd_position->x++;
    cd_position->y--;
}

void t_info_run(List *cd, List *e)
{
    TASK_CD(cd, Position, cd_position);
    
    printf("Position: { x: %d, y: %d }\n",
           cd_position->x,
           cd_position->y);
}

int main()
{
    Box *b;
    Entity *text;

    b = box_create();

    graphics_create(b);

    box_component(b, c_position_create);
    box_archetype(b, "Cube", "Position", 0);
    box_entity(b, "Cube");
    box_task(b, t_move_run, "Position", 0);
    box_task(b, t_info_run, "Position", 0);

    box_archetype(b, "Text", "GraphicsImage", 0);
    text = box_entity(b, "Text");
    TASK_CD(text->data, GraphicsImage, cd_image);
    cd_image->filename = "App/assets/text.bmp";

    graphics_loop(b);

    graphics_destroy(b);
    box_destroy(b);
}
