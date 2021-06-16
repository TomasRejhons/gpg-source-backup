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
 
package cz.ive.gui.subwindow;

import cz.ive.logs.*;
import cz.ive.gui.*;
import cz.ive.gui.icon.*;

import java.util.*;
import javax.swing.*;

/**
 * Simple Subwindow wraper for GuiLog.
 *
 * @author ondra
 */
public class LogSubwindow implements Subwindow {
    
    /** Common info for LogSubwindows */
    protected static Info LOG_INFO = new Info("Log", 
            "Panel with ordered and filtered log messages", IconBag.LOG_PANEL);
    
    /** String identification of the log subwindow. */
    public static String LOG = "Log";
    
    /** Instance specific info, if neccessary */
    protected Info info = LOG_INFO;
    
    /** Responsible Subwindow container */
    protected SubwindowContainer container;
    
    /** Instance of the GuiLog, the log itself */
    protected GuiLog guiLog;
    
    /** Are we on the screen? Should we update? */
    protected boolean invisible = true;
    
    /** Creates a new instance of LogSubwindow */
    public LogSubwindow() {
        guiLog = new GuiLog(this);
    }
    
    /**
     * Retrives Info for this Subwindow.
     *
     * @return Info filled with data about this Subwindow
     */
    public Info getInfo() {
        return info;
    }
    
    /**
     * Sets responsible SubwindowContainer.
     *
     * @param container SubwindowContainer newly responsible for this Subwindow
     */
    public void setSubwindowContainer(SubwindowContainer container) {
        this.container = container;
    }
    
    /**
     * Query wether this Subwindow accepts (can view) a given Object.
     *
     * @param object that is being offered.
     * @return Info representing action with the object if it can be accepted or
     *      <code>null</code> if not.
     */
    public Info canAccept(Object object) {
        return null;
    }
    
    /**
     * Does the subwindow already contain a given object?
     *
     * @param object that is querried.
     * @return <code>true</code> iff the object is already viewed by 
     *      this window.
     */
    public boolean contain(Object object) {
        if (object instanceof String) {
            return LOG.equals((String)object);
        }
        return false;
    }
    
    /**
     * Accept (view) the object. This can be called only after successfull 
     * call to canAccept.
     *
     * @param object that is being offered.
     */
    public void accept(Object object) {
    }
    
    /**
     * Retrives root panel of this Subwindow. It is not necessarilly 
     * this class, for example in case that we use some ToolBars and other 
     * controls. So whenever the Subwindow component is to be added to some 
     * container, the panel return by this call should be added instead 
     * of instance of this class.
     *
     * @return root panel of this GUI component
     */
    public JComponent getPanel() {
        return guiLog;
    }
    
    /**
     * Marks this Subwindow as invisible. That means it does not have to update 
     * itsef.
     *
     * @param invisible <code>true</code> iff this Subwindow is not currently
     *      on the screen.
     */
    public void setInvisible(boolean invisible) {
        this.invisible = invisible;
        if (!invisible) {
            guiLog.processMessages();
        }
    }
    
    /**
     * Is this Subwindow invisible?
     *
     * @return <code>true</code> iff this Subwindow is not currently
     *      on the screen.
     */
    public boolean isInvisible() {
        return invisible;
    }
    
    /**
     * Forces the Subwindow to revalidate its contents. This is called when
     * major parts of current simulation were changed (e.g. after a load).
     *
     * @return <code>true</code> iff the subwindow should be closed, since its
     *      contents are not valid any more.
     */
    public boolean revalidateSubwindow() {
        return false;
    }
    
    /**
     * Subwindow was just closed.
     */
    public void closed() {
        Log.removeReceiver(guiLog);
    }
    
    /**
     * Subwindow was just opened.
     */
    public void opened() {
        Log.addReceiver(guiLog);
    }
}
