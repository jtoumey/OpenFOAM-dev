/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2015-2019 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "makeReactionThermo.H"
#include "makeThermo.H"

#include "rhoReactionThermo.H"
#include "heRhoThermo.H"

#include "specie.H"
#include "perfectGas.H"
#include "rPolynomial.H"
#include "rhoConst.H"

#include "sensibleEnthalpy.H"

#include "hRefConstThermo.H"
#include "eRefConstThermo.H"
#include "janafThermo.H"

#include "constTransport.H"

#include "pureMixture.H"
#include "multiComponentMixture.H"

#include "thermoPhysicsTypes.H"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

// Thermo type typedefs:

typedef
constTransport
<
    species::thermo
    <
        hRefConstThermo
        <
            perfectGas<specie>
        >,
        sensibleEnthalpy
    >
> constRefGasHThermoPhysics;

typedef
constTransport
<
    species::thermo
    <
        hRefConstThermo
        <
            rPolynomial<specie>
        >,
        sensibleEnthalpy
    >
> constRefFluidHThermoPhysics;

typedef
constTransport
<
    species::thermo
    <
        eRefConstThermo
        <
            perfectGas<specie>
        >,
        sensibleInternalEnergy
    >
> constRefGasEThermoPhysics;

typedef
constTransport
<
    species::thermo
    <
        eRefConstThermo
        <
            rPolynomial<specie>
        >,
        sensibleInternalEnergy
    >
> constRefFluidEThermoPhysics;

typedef
constTransport
<
    species::thermo
    <
        eRefConstThermo
        <
            rhoConst<specie>
        >,
        sensibleInternalEnergy
    >
> constRefRhoConstEThermoPhysics;

typedef
constTransport
<
    species::thermo
    <
        hRefConstThermo
        <
            rhoConst<specie>
        >,
        sensibleEnthalpy
    >
> constRefRhoConstHThermoPhysics;

typedef
constTransport
<
    species::thermo
    <
        janafThermo
        <
            rhoConst<specie>
        >,
        sensibleInternalEnergy
    >
> constJanafRhoConstEThermoPhysics;


// pureMixture, sensibleEnthalpy:

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleEnthalpy,
    hRefConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleEnthalpy,
    hRefConstThermo,
    rPolynomial,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleEnthalpy,
    hRefConstThermo,
    rhoConst,
    specie
);


// pureMixture, sensibleInternalEnergy:

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    eRefConstThermo,
    perfectGas,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    eRefConstThermo,
    rPolynomial,
    specie
);

makeThermos
(
    rhoThermo,
    heRhoThermo,
    pureMixture,
    constTransport,
    sensibleInternalEnergy,
    eRefConstThermo,
    rhoConst,
    specie
);


// multiComponentMixture, sensibleInternalEnergy:

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constRefGasEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constRefFluidEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constRefRhoConstEThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constJanafRhoConstEThermoPhysics
);


// multiComponentMixture, sensibleEnthalpy:

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constRefRhoConstHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constRefFluidHThermoPhysics
);

makeThermoPhysicsReactionThermos
(
    rhoThermo,
    rhoReactionThermo,
    heRhoThermo,
    multiComponentMixture,
    constRefGasHThermoPhysics
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //
