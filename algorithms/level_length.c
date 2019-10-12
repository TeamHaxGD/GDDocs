//Get the length of a level in seconds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

const float slow_speed = 251.16;
const float normal_speed = 311.58;
const float medium_speed = 387.42;
const float fast_speed = 468.0;
const float very_fast_speed = 576.0;

typedef enum
{
	slow = 200,
	normal = 201,
	medium = 202,
	fast = 203,
	very_fast = 1334
} portal_type;

typedef struct
{
	float x;
	portal_type type;
} portal;

float get_speedportal_const(portal_type type)
{
	switch (type)
	{
	case slow:
		return slow_speed;
	case medium:
		return medium_speed;
	case fast:
		return fast_speed;
	case very_fast:
		return very_fast_speed;
	default:
		return normal_speed;
	}
}

float get_seconds_from_xpos(float pos, portal_type type, const portal **portals, int portals_num)
{
	float speed = 0.0;
	float last_obj_pos = 0.0;
	float last_segment = 0.0;
	float segments = 0.0;

	speed = get_speedportal_const(type);

	if (!portals_num)
		return pos / speed;

	for (int i = 0; i < portals_num; i++)
	{
		float s = portals[i]->x - last_obj_pos;

		if (pos >= s) break;

		s /= speed;
		last_segment = s;
		segments += s;

		speed = get_speedportal_const(portals[i]->type);

		last_obj_pos = portals[i]->x;
	}

	return ((pos - last_segment) / speed) + segments;
}

int main()
{
	portal *portals[3];

	portals[0] = calloc(1, sizeof(portal));
	portals[0]->x = 6559.5;
	portals[0]->type = medium;

	portals[1] = calloc(1, sizeof(portal));
	portals[1]->x = 6688.5;
	portals[1]->type = normal;

	portals[2] = calloc(1, sizeof(portal));
	portals[2]->x = 6822.5;
	portals[2]->type = fast;

	float t = get_seconds_from_xpos(6855.0, normal, portals, 3);
	assert(floorf(t) == 22);
  
  return 0;
}
