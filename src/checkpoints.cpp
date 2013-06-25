// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (     0, uint256("0x3702b0ae46c7d1bca40a84f5467a9c3cfd03ed2be30731d370165e9ab5e0be76"))
        (  1000, uint256("0x12ffada4e73c653cf189fe07ec144c2bbac8b8e95ae569df45c7850cafc3cacd"))
        (  2000, uint256("0x2615d00b743e13f8c7a9b87afdc15883aa369d1a5648fab9ffcb2a78507c6701"))
        (  3000, uint256("0xb3b895054710ebe930ba951fb36aaab0529692efc6cfcf13e74563eea5ae9b7d"))
        (  4000, uint256("0x296760f209219161e1845dbdf7071e7669edb191efdf3d3f3eaf98ebdec5e776"))
        (  5000, uint256("0xa0a272cee8d349a78295bc88df5357a350ca52aefc0ca3f997477119ce9b43d7"))
        ;

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
