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
        (  6000, uint256("0x15c20b37255271e2a41cafb42cf3a00821bb9f4428ecc7d0919a001cd59f9355"))
        (  7000, uint256("0x0503fcc9255ae01736e49d2e98b073f9341706f04e85428b8626e51fdec014fc"))
        (  8000, uint256("0x7755c70dd5f84744c82bf20967b5bb4e4243a3b55e398b1fa615e4b76dc9b45a"))
        (  9000, uint256("0x52774f08d627266d1bf91042940aee29dc2d7b843e7b40caf456378e23d2c13f"))
        ( 10000, uint256("0xabcac989dfa666c36416b9c8afbbc27c6a12fdf8d881da20802c27604731571b"))
        ( 11000, uint256("0xa2f2744b8a45c6542ce9e754ca8125b74a6a00526df4ba24421bd74eaadf51e3"))
        ( 12000, uint256("0x5b46ac0cab098a83af23a716412586ecf175f15e48ace8f422f5779ed81335fe"))
        ( 13000, uint256("0xbc0375c0b316fd6b827f6c70a20f5270d99c64b718725b1fe8ef0562fcde3be5"))
        ( 14000, uint256("0x32ae15bdafc6006bab99c84cec9e3770f5b8a93f4999ef048b1824e608a29f45"))
        ( 15000, uint256("0xe4e7943015dec90cccb5e104de6cd7ff215e76b67756ffc446cb23c852bb9390"))
        ( 16000, uint256("0x73607f5cd7a8b8fc9c041376274fe6d67277bb1f5589ea7438d204bb6acf7645"))
        ( 17000, uint256("0x8fc888e2a08c00aa461dff46ee48f6f707127d338a18c0248ff232461afba8a1"))
        ( 18000, uint256("0x9f227b84241eafcd7c287ba18b017bb4a5b9d382f658c57b1863dee55857f540"))
        ( 19000, uint256("0xbe51a3271610298dc96f1531adad7e6c36e3d9177fcece1c20b05d292f0ead80"))
        ( 20000, uint256("0xa8692261a5476db068d0b16d41ab58e97d8a2c9064c21c2efb51a27ae7493303"))
        ( 21000, uint256("0xb3e45d6b185afa1865c841e08d49bb723573f6bcae547dcd4d1cd24aed87a636"))
        ( 22000, uint256("0x9ad139dab34831b6b3fe81e78695b5f6147ba3083dfc3833b33a9999ffb61f6e"))
        ( 23000, uint256("0xed4838ffbead019abd82a4b20d8e01f2ef67a00af174c506f4a60dd3a33ca510"))
        ( 24000, uint256("0x09fb2aa9d799326d62038e5252e85dae75d823376eb35e992e08e4b7596a97b8"))
        ( 25000, uint256("0x7797172c030a25db63594f579d04cf3b2f7d7badb459b656f20dfc835700c53f"))
        ( 26000, uint256("0xfc1698c04c1bb9bc419e9f6b42ab162bc9d315986b20ca834f461285ce1d2bbb"))
        ( 27000, uint256("0xeaa55e58c47ced7f04dd50379b3579a5dad0fb6fe360b57b512043641176634d"))
        ( 28000, uint256("0x33280921057bf5157b154a7e2f3d76faf11a914df9c11a4234c1a2b0ff95a52a"))
        ( 29000, uint256("0x5e41d52db4e8dd678a3e19e4a046d19f94c09022c478db03dec0d6f12551f596"))
        ( 30000, uint256("0x6e160609a148e51f3cf1061aeec26091b0270a8ae888cf9ecc7a37afc8203ecd"))
        ( 31000, uint256("0xe46ea3093aec4f9030f039dee9b387bb9df73f4b96c7a163b0850bdb14aa802d"))
        ( 32000, uint256("0x97a332c6a4b5656ca629c2b5088d9380318dbec938fbf1e40b146c9f34e361e4"))
        ( 33000, uint256("0xbdcf1ab134e17ee3472a9f9583b3b64753534dd325bcec60a6e1344b6e6ddc65"))
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
