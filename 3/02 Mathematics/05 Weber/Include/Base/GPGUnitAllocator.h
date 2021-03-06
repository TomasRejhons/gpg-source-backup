/******************************************************************************
IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.

By downloading, copying, installing or using the software you agree to this
license. If you do not agree to this license, do not download, install,
copy or use the software.

Intel Open Source License for "Improved Bones Deformation" and
"Constrained Inverse Kinematics" sample code

Copyright (c) 2002, Intel Corporation.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright notice, this
	list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice,
	this list of conditions and the following disclaimer in the documentation
	and/or other materials provided with the distribution.
* Neither the name of Intel Corporation nor the names of its contributors may
	be used to endorse or promote products derived from this software without
	specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ''AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE INTEL CORPORATION OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
EXPORT LAWS: THIS LICENSE ADDS NO RESTRICTIONS TO THE EXPORT LAWS OF YOUR
JURISDICTION. It is each licensee's responsibility to comply with any export
regulations applicable in each licensee's jurisdiction.
******************************************************************************/
//
//	GPGSharedUnitAllocator.h
//
//	DESCRIPTION
//		This module defines the GPGUnitAllocator class.  It provides
//	a "fast" alternative to the standard NEW and DELETE operators provided
//	by C++.  The allocator doles out "unitSize" chunks of memory, manages a
//	freelist, and grows by "growSize" when the current memory has been 
//	exhausted.
//
//	NOTES
//		Since GPGUnitAllocator::Allocate() does not call new(),
//	it does not call any constructors.  If your pointers are to
//	classes, you will presumably have to supply and call you own
//	function to initialize the class.
//

#ifndef GPGUNITALLOCATOR_DOT_H
#define GPGUNITALLOCATOR_DOT_H

class GPGUnitAllocator
{

public:

	GPGUnitAllocator();
	~GPGUnitAllocator();

	GPGRESULT  Initialize(U32 unitSize, U32 numUnits, U32 numGrowUnits);
	void       Deallocate(U8* pPtr);
	U32        SizeList();
	U32        NumAllocatedUnits();
	U32		   NumFreeUnits();
	U8        *Allocate();

private:

	U8  *m_pHeap;             // Pointer to allocated memory chunk
	U8	*m_pFree;             // Pointer to first element of free list
	U8	*m_pEnd;			  // Always points to the "next" pointer at end of LAST chuck

	U32  m_unitSize;          // Size in bytes of each "Unit"
	U32	 m_numUnits;          // Number of units in initial allocation
	U32	 m_numGrowUnits;      // Grow by this many "Units" when memory is exhausted
    U32  m_firstSegmentSize;  // Size in buytes of first segment
    U32  m_growSegmentSize;   // Size in bytes of grow segment
	U32	 m_freeListSize;      // Num objects on free list
	U32	 m_allocListSize;     // Num allocated objects
    U32  m_uNumGrownSegments; // Number of segments grown dynamically

	GPGRESULT  ThreadMemory(U8 *pPtr);
    GPGRESULT  Destroy();
	U8        *Grow();
};


GPGINLINE U32 GPGUnitAllocator::SizeList()
{ 
	return (m_allocListSize + m_freeListSize); 
}

GPGINLINE U32 GPGUnitAllocator::NumAllocatedUnits()
{ 
	return (m_allocListSize); 
}

GPGINLINE U32 GPGUnitAllocator::NumFreeUnits()
{ 
	return (m_freeListSize); 
}

GPGINLINE U8 *GPGUnitAllocator::Allocate()
{
	U8 *pPtr = m_pFree;

	if( m_freeListSize == 0 )
	{
		// Memory exhausted - Need to allocate new memory
		if( !(pPtr = Grow()) ) return NULL;
	}

	// Retrieve the next free block from first 4 bytes of pPtr
	m_pFree = (U8 *) *((U8**) pPtr);

	m_freeListSize --;
	m_allocListSize ++;

	return pPtr;
}


GPGINLINE void GPGUnitAllocator::Deallocate(U8 *pPtr)
{
	if( m_freeListSize == 0 )
	{
		// FreeList is empty, simply point m_pFree to newly freed node
		m_pFree = pPtr;
	}
	else
	{
		// FreeList is !empty, point newly freed block to what m_pFree
		// was pointing to and set m_pFree to the new node.
		// Put NextBlock address into first 4 bytes of pPtr
		U8 *tmpPtr = m_pFree;

		*((U8**) pPtr) = (U8*)tmpPtr;	
		m_pFree = pPtr;
	}

	m_freeListSize++;
	m_allocListSize--;
}


#endif
