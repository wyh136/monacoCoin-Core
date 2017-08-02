// Copyright (c) 2012-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "compat/sanity.h"
#include "key.h"
#include "base58.h"
#include "test/test_monacoCoin.h"

#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(sanity_tests, BasicTestingSetup)

BOOST_AUTO_TEST_CASE(basic_sanity)
{
  CKey key;
  CPubKey pubkey;
  key.MakeNewKey(false);  
   pubkey = key.GetPubKey();
   BOOST_MESSAGE(key.GetPrivKey().size());
   BOOST_MESSAGE(typeid(key.GetPrivKey()).name());   
   BOOST_MESSAGE(key.GetPubKey().size());
   BOOST_MESSAGE(typeid(key.GetPubKey()).name());
   BOOST_MESSAGE(HexStr(pubkey.begin(), pubkey.end()));
   BOOST_MESSAGE(CBitcoinSecret(key).ToString());
   
   /*CKey key;
    CPubKey pubkey;
    int nCount = 0;
    do
    {
        key.MakeNewKey(false);
        pubkey = key.GetPubKey();
        nCount++;
    } while (nCount < 10000 && strPrefix != HexStr(pubkey.begin(), pubkey.end()).substr(0, strPrefix.size()));

    if (strPrefix != HexStr(pubkey.begin(), pubkey.end()).substr(0, strPrefix.size()))
        return Value::null;

    Object result;
    result.push_back(Pair("PublicKey", HexStr(pubkey.begin(), pubkey.end())));
    result.push_back(Pair("PrivateKey", CBitcoinSecret(key).ToString()));*/
   
  BOOST_CHECK_MESSAGE(glibc_sanity_test() == true, "libc sanity test");
  BOOST_CHECK_MESSAGE(glibcxx_sanity_test() == true, "stdlib sanity test");
  BOOST_CHECK_MESSAGE(ECC_InitSanityCheck() == true, "openssl ECC test");
  
}

BOOST_AUTO_TEST_SUITE_END()
