// GANoiseMSineOsc - Interface
// --------------------------------------------------------------------------------------------------------
// System:		ATOMGAUD
// Description:	...
//				...
//				...
// Location:	http://www.visiomedia.com/rooms/labor/src/sphinxmmos/index.htm
// Version:		0401
// Author:		Frank Luchs
// History:
//				1996-05-07	first draft
// --------------------------------------------------------------------------------------------------------
// This is part of Sphinx MMOS, the open source version of Sphinx Modular Media.
// Copyright � 1985-2001 Visiomedia Software Corporation, All Rights Reserved.
// --------------------------------------------------------------------------------------------------------

#ifndef _atomosGANoiseMSineOsc_
#define _atomosGANoiseMSineOsc_


#ifdef ATOMOS
namespace atomos
{
#endif // ATOMOS
// forward declarations:



interface IGANoiseMSineOsc : public IGAOscillator
{



}; // interface


class ATOMGAUD_DLLCLASS CGANoiseMSineOsc : public CGAOscillator  
{
public:

	// IObject
	enum { CID = CID_GANoiseMSineOsc };
	static const CClass classCGANoiseMSineOsc;
	virtual const IClass*		GetClass();

	virtual void Terminate();
	virtual UINT32 Process(IObject* pob);

	// IGANoiseMSineOsc


	// CTOR / DTOR
	CGANoiseMSineOsc();
	~CGANoiseMSineOsc();

protected:


	CGARandom m_Random;

};

#ifdef ATOMOS
} // namespace atomos
#endif // ATOMOS

#endif // _atomosGANoiseMSineOsc_
// --------------------------------------------------------------------------------------------------------
