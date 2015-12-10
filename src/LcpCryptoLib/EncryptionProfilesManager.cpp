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

#include "EncryptionProfilesManager.h"
#include "Lcp1dot0EncryptionProfile.h"

namespace lcp
{
    EncryptionProfilesManager::EncryptionProfilesManager()
    {
        std::unique_ptr<IEncryptionProfile> lcp1dot0(new Lcp1dot0EncryptionProfile());
        m_profilesMap.insert(std::make_pair(lcp1dot0->Name(), std::move(lcp1dot0)));
    }

    bool EncryptionProfilesManager::RegisterProfile(std::unique_ptr<IEncryptionProfile> profile)
    {
        auto res = m_profilesMap.insert(std::make_pair(profile->Name(), std::move(profile)));
        return res.second;
    }

    IEncryptionProfile * EncryptionProfilesManager::GetProfile(const std::string & name) const
    {
        auto profileIt = m_profilesMap.find(name);
        if (profileIt != m_profilesMap.end())
        {
            return profileIt->second.get();
        }
        return nullptr;
    }
}