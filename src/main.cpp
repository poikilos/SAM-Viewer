#include <stdlib.h>
#include <iostream>
#include <irrlicht.h>

#include "config.h"
#include "viewer.h"

int main()
{
	Config *conf = new Config("../bin/config.ini");
	std::map<std::string, std::string> defaults = {
		{"model_mesh", "character.b3d"},
		{"model_position", "0,-10,0"},
		{"model_rotation", "0,0,0"},
		{"model_scale", "100"},
		{"model_material", "14"},
		{"model_texture_1", "character.png"},
		{"model_texture_2", "blank.png"},
		{"model_texture_3", "blank.png"},
		{"model_texture_4", "blank.png"},
		{"model_texture_5", "blank.png"},
		{"model_texture_6", "blank.png"},
		{"model_texture_single", "false"},
		{"wield_mesh", "pickaxe.obj"},
		{"wield_position", "0,5,0"},
		{"wield_rotation", "0,0,0"},
		{"wield_scale", "400"},
		{"wield_material", "14"},
		{"wield_show", "true"},
		{"wield_bone", "Arm_Right"},
		{"wield_texture_1", "pickaxe.png"},
		{"wield_texture_2", "blank.png"},
		{"wield_texture_3", "blank.png"},
		{"wield_texture_4", "blank.png"},
		{"wield_texture_5", "blank.png"},
		{"wield_texture_6", "blank.png"},
		{"wield_texture_single", "false"},
		{"lighting", "false"},
		{"light_type_1", "0"},
		{"light_enabled_1" , "true"},
		{"light_color_diffuse_1", "FFFFFF"},
		{"light_color_ambient_1", "111111"},
		{"light_color_specular_1", "000000"},
		{"light_position_1", "0,15,0"},
		{"light_rotation_1", "90,45,0"},
		{"light_radius_1", "100"},
		{"light_type_2", "1"},
		{"light_enabled_2" , "true"},
		{"light_color_diffuse_2", "AAAAFF"},
		{"light_color_ambient_2", "000000"},
		{"light_color_specular_2", "000000"},
		{"light_position_2", "15,15,15"},
		{"light_rotation_2", "150,45,0"},
		{"light_radius_2", "50"},
		{"light_type_3", "2"},
		{"light_enabled_3" , "true"},
		{"light_color_diffuse_3", "220000"},
		{"light_color_ambient_3", "070000"},
		{"light_color_specular_3", "000000"},
		{"light_position_3", "-15,15,15"},
		{"light_rotation_3", "150,-45,0"},
		{"light_radius_3", "100"},
		{"anim_start", "168"},
		{"anim_end", "187"},
		{"anim_speed", "15"},
		{"ortho", "false"},
		{"bilinear", "false"},
		{"trilinear", "false"},
		{"anisotropic", "false"},
		{"backface_cull", "true"},
		{"bg_color", "808080"},
		{"grid_color", "404040"},
		{"screen_width", "800"},
		{"screen_height","600"},
		{"debug_info", "false"},
		{"debug_flags", "1"},
		{"export_flags", "1"},
		{"export_scale", "100"}
	};
	conf->load();
	for (std::map<std::string, std::string>::iterator it = defaults.begin();
		it != defaults.end(); it++)
	{
		if (!conf->hasKey(it->first))
			conf->set(it->first, it->second);
	}
	conf->save();

	u32 width = conf->getInt("screen_width");
	u32 height = conf->getInt("screen_height");
	IrrlichtDevice *device = createDevice(EDT_OPENGL,
		dimension2d<u32>(width, height), 16, false, false, false);

	if (device && conf)
	{
		Viewer *viewer = new Viewer(conf);
		viewer->run(device);
		device->drop();
		delete viewer;
		delete conf;
	}
	return 1;
}
