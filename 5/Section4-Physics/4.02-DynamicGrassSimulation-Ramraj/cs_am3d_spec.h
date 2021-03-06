#ifndef __CS_AM3D_SPEC_H__
#define __CS_AM3D_SPEC_H__
//----------------------------------------------------------------------------
//
//cs_am3d_spec.h
//
//Copyright Е Rishi Ramraj, 2004
//am3d file spec
// The data structures are defined in the order as they appear in the .am3d file.
// The .am3d file is one of three types of files, which produce a modular system 
// suitable for games and 3d demos. Refer to the Character SDK 3D specifications
// document.
//----------------------------------------------------------------------------

//ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//
//    header :: Inclusions
//ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//

//ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//
//    header :: Definitions
//ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//

//ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//
//    header :: Structures
//ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//

//Basic Typesиииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//

#ifndef byte
typedef unsigned char byte;
#endif // byte

#ifndef word
typedef unsigned short word;
#endif // word

//
// The number of vertices
//
//word numVertices;

//
// numVertices * sizeof (ms3d_vertex_t)
//
typedef struct
{
	bool	selected;
	char	boneID;
    float   vertex[3];
} am3d_vertex_t;

//
// number of triangles
//
//word numTriangles;

//
// numTriangles * sizeof (am3d_triangle_t)
//
typedef struct
{
	bool	selected;
    word    vertexIndices[3];
	float	vertexNormals[3][3];
    float   s[3];
    float   t[3];
} am3d_triangle_t;

//Formatииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//

//
// number of groups
//
//word numGroups;

//group rendering offsets:
//word solidGroups;
//word texturedGroups;
//word maskedGroups;

//
// numGroups * sizeof (am3d_group_t)
//
typedef struct
{
	bool	selected;		
    word	numtriangles;
    word *	triangleIndices;
    char	materialIndex;
} am3d_group_t;

//
// number of materials
//
//word nNumMaterials;

//
// numMaterials * sizeof (am3d_material_path_t)
//
typedef struct
{
	char TexName[128];
	char AlphaName[128];
} am3d_material_path_t;

//ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//
//    header :: Class Defs
//ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//

//ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//
//    header :: Function Defs
//ииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииииии//

//----------------------------------------------------------------------------
//cs_am3d_spec.h
//Copyright Е Rishi Ramraj, 2004
//----------------------------------------------------------------------------
#endif //__CS_AM3D_SPEC_H__