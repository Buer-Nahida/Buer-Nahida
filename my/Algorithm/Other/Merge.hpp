#pragma once

namespace star {
template <typename Type0, typename Type1, typename TypeTarget>
void Merge(Type0 iterStart0, Type0 iterEnd0, Type1 iterStart1, Type1 iterEnd1,
           TypeTarget iterTarget) {
    for (; iterStart0 != iterEnd0 && iterStart1 != iterEnd1; ++iterTarget) {
        if (*iterStart0 <= *iterStart1) {
            *iterTarget = *iterStart0;
            ++iterStart0;
        } else {
            *iterTarget = *iterStart1;
            ++iterStart1;
        }
    }
    if (iterStart0 != iterEnd0) {
        for (; iterStart0 != iterEnd0; ++iterStart0, ++iterTarget) {
            *iterTarget = *iterStart0;
        }
    } else {
        for (; iterStart1 != iterEnd1; ++iterStart1, ++iterTarget) {
            *iterTarget = *iterStart1;
        }
    }
}
}
