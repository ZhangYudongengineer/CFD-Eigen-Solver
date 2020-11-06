#ifndef __XMOMENTUMEQN_H__
#define __XMOMENTUMEQN_H__

#include "TransportEqn.h"
#include "Inputs.h"

class XMomentumEqn : public TransportEqn
{
private:
    double mu;

    MatrixCoeff<XMomentumEqn>* mat;

    double gamma() override { return mu; }
    double density() override { return rho; }
    void init_S();
public:
    XMomentumEqn(Mesh* mesh, Field* field, Inputs* inputs, MatrixCoeff<XMomentumEqn>* matrix_coeff, Boundary* boundary, Source* source)
         : TransportEqn(mesh, field, inputs, boundary, source)
    {
        mu = inputs->physcial_properties.mu;

        mat = matrix_coeff;

        init_S();
    }

    TransportEqn& addConvectionTerm() override;
    TransportEqn& addDiffusionTerm() override;
    TransportEqn& addSourceTerm() override;
};

#endif