//
//  Created by Mickaël Menu on 02/11/15.
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

#import <Foundation/Foundation.h>

#ifdef __cplusplus
namespace lcp {
    class ILicense;
}
#endif


@interface LCPLicense : NSObject

@property (readonly, nonatomic) NSString *identifier;
@property (readonly, nonatomic) BOOL isDecrypted;

@property (readonly, nonatomic) NSString *userHint;

#ifdef __cplusplus
@property (readonly, nonatomic) lcp::ILicense *nativeLicense;
- (instancetype)initWithLicense:(lcp::ILicense *)nativeLicense NS_DESIGNATED_INITIALIZER;
#endif

@end