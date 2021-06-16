/* 
 *
 * IVE Editor 
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
 
package cz.ive.process;

/**
 * Process Template for non-interesting processes that just wait for a while
 * and then finish.
 *
 * @author ondra
 */
public class DummyProcess extends CommonProcessTemplate {
    
    /** Default wait time of 5 s-seconds */
    protected static final int DEFAULT_WAIT = 5000;
    
    /** Wait time */
    protected int waitTime = DEFAULT_WAIT;
    
    /** Creates a new instance of DummyProcess */
    public DummyProcess() {
    }
    
    /** 
     * Creates a new instance of DummyProcess 
     *
     * @param waitTime wait time of this dummy process
     */
    public DummyProcess(int waitTime) {
        this.waitTime = waitTime;
    }
    
    /**
     * Just do nothing, but for the specified time.
     *
     * @param execution ProcessExecution representing the running process
     */
    public ProcessResult atomicCommit(ProcessExecution execution) {
        if (execution.getDuration() < waitTime)
            return ProcessResult.RUNNING;
        
        return ProcessResult.OK;
    }

    public long atomicLength(ProcessExecution execution) {
        return Math.max(waitTime - execution.getDuration(), 0);
    }
}