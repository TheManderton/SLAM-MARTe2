/**
 * @file Product.cpp
 * @brief Source file for class Product
 * @date 06/04/2018
 * @author Andre Neto
 *
 * @copyright Copyright 2015 F4E | European Joint Undertaking for ITER and
 * the Development of Fusion Energy ('Fusion for Energy').
 * Licensed under the EUPL, Version 1.1 or - as soon they will be approved
 * by the European Commission - subsequent versions of the EUPL (the "Licence")
 * You may not use this work except in compliance with the Licence.
 * You may obtain a copy of the Licence at: http://ec.europa.eu/idabc/eupl
 *
 * @warning Unless required by applicable law or agreed to in writing, 
 * software distributed under the Licence is distributed on an "AS IS"
 * basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
 * or implied. See the Licence permissions and limitations under the Licence.

 * @details This source file contains the definition of all the methods for
 * the class Product (public, protected, and private). Be aware that some 
 * methods, such as those inline could be defined on the header file, instead.
 */

/*---------------------------------------------------------------------------*/
/*                         Standard header includes                          */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                         Project header includes                           */
/*---------------------------------------------------------------------------*/
#include "AdvancedErrorManagement.h"
#include "Product.h"

/*---------------------------------------------------------------------------*/
/*                           Static definitions                              */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                           Method definitions                              */
/*---------------------------------------------------------------------------*/
namespace MARTe {
Product::Product() : GAM() {
    inputSignalA = NULL_PTR(uint32 *);
    inputSignalB = NULL_PTR(uint32 *);
    outputSignal = NULL_PTR(uint32 *);
}

Product::~Product() {
}

bool Product::Initialise(StructuredDataI & data) {
    bool ok = GAM::Initialise(data);
	
    return ok;
}

bool Product::Setup() {

    inputSignalA = reinterpret_cast<uint32 *>(GetInputSignalMemory(0u));
    inputSignalB = reinterpret_cast<uint32 *>(GetInputSignalMemory(1u));
    outputSignal = reinterpret_cast<uint32 *>(GetOutputSignalMemory(0u));
    
    return true;
}

bool Product::Execute() {
    *outputSignal = *inputSignalA * *inputSignalB;
    return true;
}

CLASS_REGISTER(Product, "")
}
