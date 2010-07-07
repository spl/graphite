#pragma once

#include "VMScratch.h"
#include "Code.h"

class Segment;
class GrFace;
class Silf;

class Pass
{   
public:
    Pass() {}
    
    bool readPass(void *pPass, size_t lPass);
    void runGraphite(Segment *seg, const GrFace *face, VMScratch *vms) const;
    int findNDoRule(Segment *seg, int iSlot, const GrFace *face, VMScratch *vms) const;
    int testConstraint(const vm::Code *codeptr, int iSlot, int num, Segment *seg, VMScratch *vms) const;
    int doAction(const vm::Code *m_cAction, int startSlot, Segment *seg, VMScratch *vms) const;
    void init(Silf *silf) { m_silf = silf; }

private:
    Silf *m_silf;
    byte m_iMaxLoop;
    uint16 m_numGlyphs;
    uint16 m_numRules;
    uint16 m_sRows;
    uint16 m_sTransition;
    uint16 m_sSuccess;
    uint16 m_sColumns;
    uint16 *m_cols;
    uint16 *m_ruleidx;
    uint16 *m_ruleMap;
    uint16 *m_ruleSorts;
    byte m_minPreCtxt;
    byte m_maxPreCtxt;
    uint16 *m_startStates;
    byte *m_rulePreCtxt;
    vm::Code m_cPConstraint;
    vm::Code *m_cConstraint;
    vm::Code *m_cActions;
    int16 *m_sTable;
    
private:		//defensive
    Pass(const Pass&);
    Pass& operator=(const Pass&);
};

