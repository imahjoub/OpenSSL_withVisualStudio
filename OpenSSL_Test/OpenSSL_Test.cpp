// -----------------------------------------------------
//  Copyright Iliass Mahjoub 2023.                     
//  Distributed under the Boost Software License,      
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)   
// -----------------------------------------------------

#include <array>
#include <iostream>

#include <openssl/sha.h>

constexpr std::array<std::uint8_t, 32U> sha256_hash_expected_result =
{
  0x41U, 0xFFU, 0xCAU, 0x92U, 0x9BU, 0x95U, 0xC4U, 0x96U,
  0x90U, 0xABU, 0x88U, 0x15U, 0xD1U, 0xD1U, 0xA1U, 0x34U,
  0xA5U, 0xBCU, 0xDDU, 0x86U, 0xBDU, 0xE4U, 0x07U, 0xC0U,
  0xF4U, 0x6BU, 0x90U, 0xEAU, 0xBFU, 0x55U, 0x6BU, 0x05U
};


const bool sha256(const uint8_t* data, const std::size_t data_length)
{
  std::array<std::uint8_t, SHA256_DIGEST_LENGTH> sha256_hash_result {0U};

  SHA256_CTX sha256;

  SHA256_Init(&sha256);

  SHA256_Update(&sha256, data, data_length);

  SHA256_Final(sha256_hash_result.data(), &sha256);

  return (sha256_hash_result == sha256_hash_expected_result);
}

int main()
{
  const std::array<std::uint8_t , 7U> data = { 'o', 'p', 'e', 'n', 's', 's', 'l' };

  const bool sha256_hash_result = sha256(data.data(), data.size());

  std::cout << "sha256_hash_result: " <<std::boolalpha << sha256_hash_result << std::endl;

}
