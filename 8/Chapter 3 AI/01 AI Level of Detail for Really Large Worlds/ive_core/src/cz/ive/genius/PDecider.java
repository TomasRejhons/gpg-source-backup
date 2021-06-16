/* 
 *
 * IVE - Inteligent Virtual Environment
 * Copyright (c) 2005-2009, IVE Team, Charles University in Prague
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 * 
 *     * Redistributions of source code must retain the above copyright notice, 
 *       this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright notice, 
 *       this list of conditions and the following disclaimer in the documentation 
 *       and/or other materials provided with the distribution.
 *     * Neither the name of the Charles University nor the names of its contributors 
 *       may be used to endorse or promote products derived from this software 
 *       without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 */
 
package cz.ive.genius;

import java.util.*;

import cz.ive.iveobject.*;
import cz.ive.process.*;
import cz.ive.sensors.*;
import cz.ive.ontology.OntologyToken;

/**
 * Process decider, chooses among variants of fulfilling goals.
 *
 * @author honza
 */
public interface PDecider {
    
    /**
     *  Chooses the best process from the variants for the given goal
     * @param goal well the goal..
     * @param sources VIP sources, that are "held" by the genius (so he knows
     *      about them and can use them).
     * @return Chosen process
     */
    public IveProcess chooseProcess(OntologyToken goal, List<IveObject> sources);
    
    /**
     * Sets sensors available for making (P)decision.
     * @param sensors
     */
    public void setSensors(List<Sensor> sensors);
}
