#include "display.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

uint32_t* color_buffer = NULL;
SDL_Texture* color_buffer_texture = NULL;

int window_width = 800;
int window_height = 600;

bool initialize_window(void) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0 ){
		fprintf(stderr, "Error initializing SDL.\n");
		return false;
	}

	// Use SDL to query what is the fullscreen max. width and window_height
	SDL_DisplayMode display_mode;
	SDL_GetCurrentDisplayMode(
		0,
		&display_mode
	);

	window_height = display_mode.h;
	window_width = display_mode.w;

   window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		window_width,
		window_height,
		SDL_WINDOW_BORDERLESS
	);

	if (!window) {
		fprintf(stderr, "Error creating SDL window.\n");
		return false;
	}

	// Create a SDL renderer
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		fprintf(stderr, "Error creating SDL renderer.\n");
		return false;
	}

	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	return true;
}


void draw_grid(void) {
	// Draw a background grid that files the entire window.
	// Lines should be rendered at every row/col multiple of 10.

	for (int y = 0; y < window_height; y += 10) {
		for (int x = 0; x < window_width; x += 10) {
			color_buffer[(window_width * y) + x] = 0xFFFFFFFF;
		}
	}
}

void draw_pixel(int x, int y, uint32_t color) {
	if (x < window_width && y < window_height) {
		color_buffer[(window_width * y) + x] = color;
	}
}

void draw_rectangle(int x, int y, int width, int height, uint32_t color) {
	int start_x = x;
	int end_x = x + width;
	int start_y = y;
	int end_y = y + height;

	for (int current_x = start_x; current_x < end_x; current_x++) {
		for (int current_y = start_y; current_y < end_y; current_y++) {
			draw_pixel(
				current_x,
				current_y,
				color
			);
		}
	}
}

void draw_line(int x0, int y0, int x1, int y1, uint32_t color) {
	int delta_x = (x1 - x0);
	int delta_y = (y1 - y0);

	int longest_side_length = abs(delta_x) > abs(delta_y) ? abs(delta_x) : abs(delta_y);

	float x_increment = delta_x / (float)longest_side_length;
	float y_increment = delta_y / (float)longest_side_length;

	float current_x = x0;
	float current_y = y0;

	for (int i = 0; i < longest_side_length; i++) {
		draw_pixel(round(current_x), round(current_y), color);
		current_x += x_increment;
		current_y += y_increment;
	}
}

void draw_triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint32_t color) {
	draw_line(x0, y0, x1, y1, color);
	draw_line(x1, y1, x2, y2, color);
	draw_line(x2, y2, x0, y0, color);
}

void render_color_buffer(void) {
	SDL_UpdateTexture(
		color_buffer_texture,
		NULL,
		color_buffer,
		(int)(window_width * sizeof(uint32_t))
	);
	SDL_RenderCopy(
		renderer,
		color_buffer_texture,
		NULL,
		NULL
	);
}

void clear_color_buffer(uint32_t color) {
	for (int y = 0; y < window_height; y++) {
		for (int x = 0; x < window_width; x++) {
			color_buffer[(window_width * y) + x] = color;
		}
	}
}

void destroy_window(void) {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
