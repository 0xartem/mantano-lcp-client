//
//  Created by Artem Brazhnikov on 11/15.
//  Copyright © 2015 Mantano. All rights reserved.
//
//  This program is distributed in the hope that it will be useful, but WITHOUT ANY
//  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//
//  Licensed under Gnu Affero General Public License Version 3 (provided, notwithstanding this notice,
//  Readium Foundation reserves the right to license this material under a different separate license,
//  and if you have done so, the terms of that separate license control and the following references
//  to GPL do not apply).
//
//  This program is free software: you can redistribute it and/or modify it under the terms of the GNU
//  Affero General Public License as published by the Free Software Foundation, either version 3 of
//  the License, or (at your option) any later version. You should have received a copy of the GNU
//  Affero General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef __I_ENCRTYPTION_PROFILE_H__
#define __I_ENCRTYPTION_PROFILE_H__

#include <string>
#include <vector>
#include "LcpUtils.h"

namespace lcp
{
    class ISymmetricAlgorithm;
    class IHashAlgorithm;
    class ISignatureAlgorithm;

    class IEncryptionProfile
    {
    public:
        virtual std::string Name() const = 0;
        virtual std::string UserKeyAlgorithm() const = 0;
        virtual std::string PublicationAlgorithm() const = 0;
        virtual std::string ContentKeyAlgorithm() const = 0;
        virtual std::string SignatureAlgorithm() const = 0;
        virtual IHashAlgorithm * CreateUserKeyAlgorithm() const = 0;
        virtual ISymmetricAlgorithm * CreatePublicationAlgorithm(const KeyType & symmetricKey) const = 0;
        virtual ISymmetricAlgorithm * CreateContentKeyAlgorithm(const KeyType & symmetricKey) const = 0;
        virtual ISignatureAlgorithm * CreateSignatureAlgorithm(const KeyType & publicKey) const = 0;
        virtual ~IEncryptionProfile() {}
    };
}

#endif //__I_ENCRTYPTION_PROFILE_H__
