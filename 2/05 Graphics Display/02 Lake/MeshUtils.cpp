/*
IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING. 

By downloading, copying, installing or using the software you agree to this 
license. If you do not agree to this license, do not download, install, 
copy or use the software. 

Intel Open Source License for Cartoon Shading in Real-Time

Copyright (c) 2001, Intel Corporation.
All rights reserved. 

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met: 
* Redistributions of source code must retain the above copyright notice, this 
list of conditions and the following disclaimer. 
* Redistributions in binary form must reproduce the above copyright notice, this 
list of conditions and the following disclaimer in the documentation and/or 
other materials provided with the distribution. 
* Neither the name of Intel Corporation nor the names of its contributors may be 
used to endorse or promote products derived from this software without specific 
prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ''AS IS'' 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE INTEL CORPORATION OR CONTRIBUTORS BE LIABLE FOR ANY 
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
EXPORT LAWS: THIS LICENSE ADDS NO RESTRICTIONS TO THE EXPORT LAWS OF YOUR 
JURISDICTION. It is each licensee's responsibility to comply with any export 
regulations applicable in each licensee's jurisdiction. 
*/

#include "MeshUtils.h"

void MeshUtils::CreateUniqueEdgeList(Mesh *pMesh, Edge **ppEdges, U32 *puNumEdges)
{
	U32 uNumFaces = pMesh->GetNumFaces();
	Face *pFace;
	U32 uEdgeIndexA, uEdgeIndexB;
	EdgeHash edgeHash;

	m_uNumEdges = 0;

	// Allocate edge hash table
	edgeHash.CreateHashTable(pMesh);

	for(U32 i=0; i < uNumFaces; i++)
	{
		pFace = pMesh->GetFacePtr(i);

		for(U32 corner=0; corner < 3; corner++)
		{
			uEdgeIndexA = pFace->Get(corner);
			uEdgeIndexB = pFace->Get((corner+1) % 3);

			edgeHash.Insert(uEdgeIndexA, uEdgeIndexB, i);
		} // end for(corner)	
	}  // end for(numFaces)

	// Allocate pool for unique edges
	*puNumEdges = edgeHash.GetNumEdges();
	*ppEdges = new Edge[*puNumEdges]; 

	// Call edgeHash to walk the hash table and get unique edges
	edgeHash.CompactEdgeTable(*ppEdges);
}

void MeshUtils::CalculateFaceNormals(Mesh *pMesh, vector3 *pFaceNormals)
{
	U32 uNumFaces = pMesh->GetNumFaces();
	vector3 *pVertexA, *pVertexB, *pVertexC;
	vector3 v1, v2;
	vector3 *pFaceNormal;
	Face *pFace;


	for(U32 i=0; i < uNumFaces; i++)
	{
		pFace = pMesh->GetFacePtr(i);
		pFaceNormal = &pFaceNormals[i];

		pVertexA = pMesh->GetVertexPosition(pFace->Get(0));
		pVertexB = pMesh->GetVertexPosition(pFace->Get(1));
		pVertexC = pMesh->GetVertexPosition(pFace->Get(2));

		// Get two vectors that form the plane
		 v1.x = pVertexA->x -  pVertexB->x;
		 v1.y = pVertexA->y -  pVertexB->y;
		 v1.z = pVertexA->z -  pVertexB->z;
		
		 v2.x = pVertexC->x -  pVertexB->x;
		 v2.y = pVertexC->y -  pVertexB->y;
		 v2.z = pVertexC->z -  pVertexB->z;

		v1.normalize();
		v2.normalize();

		// Calculate crossproduct of v1 and v2 to from the face normal
		*pFaceNormal = CrossProduct(v1, v2);

		pFaceNormal->normalize();
	}
}