#include "renderable.h"
#include "error.h"

#include "instance_object.h"

instance_object* instance_object_new() {
  instance_object* io = malloc(sizeof(instance_object));
  
  io->num_instances = 0;
  io->instances = malloc(sizeof(instance_data) * 0);
  
  io->active = true;
  io->recieve_shadows = true;
  io->cast_shadows = true;
  
  io->renderable = NULL;
  io->collision_body = NULL;
  
  return io;
}

void instance_object_delete(instance_object* io) {
  free(io->instances);
  free(io);
}

void instance_object_add_instance(instance_object* io, vector3 position, vector3 scale, vector4 rotation) {
  
  if (io->num_instances == MAX_INSTANCES) {
    warning("Max number of instances %i reached for instance object!", MAX_INSTANCES);
    return;
  }
  
  instance_data id;
  id.position = position;
  id.scale = scale;
  id.rotation = rotation;
  
  io->num_instances++;
  io->instances = realloc(io->instances, sizeof(instance_data) * io->num_instances);
  io->instances[io->num_instances-1] = id;
  
}