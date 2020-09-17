#include "Nivel3.h"

Nivel3::Nivel3()
{

}

void Nivel3::must_init(bool test, const char* description)
{
    if (test) return;
    printf("couldn't initialize %s\n", description);
    exit(1);
}

void Nivel3::Logica()
{
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_BITMAP* fondo;
    ALLEGRO_FONT* font = al_load_ttf_font("YARDSALE.ttf", 64, 0);
    ALLEGRO_FONT* font2 = al_load_ttf_font("YARDSALE.ttf", 36, 0);
    ALLEGRO_COLOR azul = al_map_rgb(0, 0, 130);
    ALLEGRO_COLOR azulHover = al_map_rgb(0, 0, 255);
    ALLEGRO_COLOR color1=azul, color2=azul;
    
    al_clear_to_color(al_map_rgb(0, 0, 0));
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    al_start_timer(timer);
    while (true) {
       
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(200, 200, 350, 250, color1);
        al_draw_filled_rectangle(SCREENW-200, 200, SCREENW-350, 250, color2);
        //al_draw_text(font, al_map_rgb(255, 255, 255), 660, 60, 0, "");

        al_flip_display();
        al_wait_for_event(queue, &event);
        bool hoverBoton1 = (event.mouse.x >= 200 && event.mouse.x < 350 && event.mouse.y < 250 && event.mouse.y>200);
        bool hoverBoton2 = (event.mouse.x <= SCREENW - 200 && event.mouse.x > SCREENW - 350 && event.mouse.y < 250 && event.mouse.y>200);
        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            if (hoverBoton1)
                color1 = azulHover;
            else
                color1 = azul;
            
            if (hoverBoton2)
                color2 = azulHover;
            else
                color2 = azul;
           
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (hoverBoton1)
            {

            }
            else if (hoverBoton2)
            {

            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    done = true;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_G) {


                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_R) {
                    
                }

            }
            break;

        case ALLEGRO_EVENT_TIMER:
            break;
        }

        if (done) {
            
            break;
        }

    }
}