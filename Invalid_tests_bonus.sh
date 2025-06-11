#!/bin/bash

echo -e "\e[1;31mInvalid RGB color 'F 20,20,-20'\n\e[0m";
valgrind ./cub3D_bonus maps/bad/color_invalid_rgb.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMissing one color ceiling 'C 200,200,'\n\e[0m";
valgrind ./cub3D_bonus maps/bad/color_missing_ceiling_rgb.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMissing one color floor 'F 20,20'\n\e[0m";
valgrind ./cub3D_bonus maps/bad/color_missing_floor_rgb.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMissing floor\n\e[0m";
valgrind ./cub3D_bonus maps/bad/color_missing.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mNo color\n\e[0m";
valgrind ./cub3D_bonus maps/bad/color_none.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mEmpty file\n\e[0m";
valgrind ./cub3D_bonus maps/bad/empty.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMap with new lines on the middle and char at the end\n\e[0m";
valgrind ./cub3D_bonus maps/bad/file_letter_end.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMissing file type\n\e[0m";
valgrind ./cub3D_bonus maps/bad/filetype_missing;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mWrong type file type\n\e[0m";
valgrind ./cub3D_bonus maps/bad/filetype_wrong.buc;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mFile without permissions\n\e[0m";
chmod 000 maps/bad/forbidden.cub
valgrind ./cub3D_bonus maps/bad/forbidden.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
chmod 777 maps/bad/forbidden.cub
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mInvalid texture file\n\e[0m";
valgrind ./cub3D maps/bad/map_invalid_texture.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mFile is a folder\n\e[0m";
valgrind ./cub3D_bonus maps/bad/test_folder.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMap before textures\n\e[0m";
valgrind ./cub3D_bonus maps/bad/map_first.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMap with new lines on the middle\n\e[0m";
valgrind ./cub3D_bonus maps/bad/map_hole.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMap before colors\n\e[0m";
valgrind ./cub3D_bonus maps/bad/map_middle.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mFile without map\n\e[0m";
valgrind ./cub3D_bonus maps/bad/map_missing.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mFile with map only\n\e[0m";
valgrind ./cub3D_bonus maps/bad/map_only.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mFile with small map without start position\n\e[0m";
valgrind ./cub3D_bonus maps/bad/map_too_small.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mPlayer closed and open map \n\e[0m";
valgrind ./cub3D_bonus maps/bad/player_closed.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMultiple start postions\n\e[0m";
valgrind ./cub3D_bonus maps/bad/player_multiple.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMap without start pos\n\e[0m";
valgrind ./cub3D_bonus maps/bad/player_none.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMap with player on the edge\n\e[0m";
valgrind ./cub3D_bonus maps/bad/player_on_edge.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mTexture file is a folder\n\e[0m";
valgrind ./cub3D_bonus maps/bad/textures_dir.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mDuplicated textures\n\e[0m";
valgrind ./cub3D_bonus maps/bad/textures_duplicates.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mTextures file without premission\n\e[0m";
chmod 000 textures/forbidden.xpm
valgrind ./cub3D_bonus maps/bad/textures_forbidden.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
chmod 444 textures/forbidden.xpm
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mNon existent texture\n\e[0m";
valgrind ./cub3D_bonus maps/bad/textures_invalid.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMissing texture\n\e[0m";
valgrind ./cub3D_bonus maps/bad/textures_missing.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mFile without any textures\n\e[0m";
valgrind ./cub3D_bonus maps/bad/textures_none.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mMap space on the middle \n\e[0m";
valgrind ./cub3D maps/bad/map_space_midle.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mHole on east wall\n\e[0m";
valgrind ./cub3D_bonus maps/bad/wall_hole_east.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mHole on north wall\n\e[0m";
valgrind ./cub3D_bonus maps/bad/wall_hole_north.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mHole on south wall\n\e[0m";
valgrind ./cub3D_bonus maps/bad/wall_hole_south.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mHole on west wall\n\e[0m";
valgrind ./cub3D_bonus maps/bad/wall_hole_west.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mmap without any wall\n\e[0m";
valgrind ./cub3D_bonus maps/bad/wall_none.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;32mBONUS TESTS\n\e[0m";

echo -e "\e[1;31mRemove keys\n\e[0m";
mv keys/rr keys/rrc;
valgrind ./cub3D_bonus maps/hugo_2x.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
mv keys/rrc keys/rr;
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mRemove other keys\n\e[0m";
mv keys/bc keys/bcc;
valgrind ./cub3D_bonus maps/hugo_2x.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
mv keys/bcc keys/bc;
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mKeys without permission\n\e[0m";
chmod 000 keys/fr;
valgrind ./cub3D_bonus maps/hugo_2x.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
chmod 444 keys/fr;
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mOther keys without permission\n\e[0m";
chmod 000 keys/bo;
valgrind ./cub3D_bonus maps/hugo_2x.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
chmod 444 keys/bo;
read -p "Press Enter to continue..."
clear ;

echo -e "\e[1;31mkeys is folder\n\e[0m";
mv keys/lf keys/lfc;
mkdir keys/lf;
valgrind ./cub3D_bonus maps/hugo_2x.cub;
echo -e "\n\e[1;31mEXIT CODE : $?\n\e[0m";
rmdir keys/lf;
mv keys/lfc keys/lf;
read -p "Press Enter to continue..."
clear ;