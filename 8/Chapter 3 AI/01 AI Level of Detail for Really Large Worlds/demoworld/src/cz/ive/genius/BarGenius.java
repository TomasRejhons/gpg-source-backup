/* 
 *
 * IVE Demo World
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

import cz.ive.genius.goaltree.RuleTreeNode;
import java.util.*;

/**
 * Area genius specialized for bar area.
 *
 * @author ondra
 */
public class BarGenius extends AreaGeniusImpl {
    
    /** Bar joy prefered process */
    static protected Set<String> barJoy = new HashSet<String>(2);
    
    static {
        barJoy.add("EmptyBarJoy");
        barJoy.add("BarJoy");
        barJoy.add("QueueBarJoy");
    }
    
    /**
     * Creates a new instance of BarGenius
     *
     * @param id Id to be assigned to the new genius.
     * @param areaId Id of the area assigned.
     */
    public BarGenius(String id, String areaId) {
        super(id, areaId);
        specialGoals.add("BarJoyGoal");
    }
    
    protected Set<String> selectSpecialProcess(RuleTreeNode rule) {
        String goalId = rule.getGoal().getGoalID();
        
        if (goalId.equals("BarJoyGoal")) {
            return barJoy;
        }
        return null;
    }
}
