// -----------------------------------------------------
//  Copyright Iliass Mahjoub 2023.                     
//  Distributed under the Boost Software License,      
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)   
// -----------------------------------------------------

#include <string.h>
#include "openssl/ec.h"
#include "openssl/ecdsa.h"
#include "openssl/bn.h"
#include "openssl/obj_mac.h"
#include "openssl/sha.h"

int main()
{
  EC_KEY         *key_pair_obj = nullptr;
  int             ret_error;
  BIGNUM         *priv_key;
  EC_POINT       *pub_key;
  EC_GROUP       *secp256k1_group;
  char           *pub_key_char, *priv_key_char;

  const char     *message = "message to sign";
  unsigned char   buffer_digest[SHA256_DIGEST_LENGTH];
  uint8_t        *digest;
  uint8_t       *signature;
  uint32_t        signature_len;
  int             verification;

  BIGNUM          *bn;
  EC_KEY          *imported_key_pair = nullptr;
  EC_GROUP        *curve_group;
  EC_POINT        *public_point;
  int              char_read;

  // Generate secp256k1 key pair
  key_pair_obj = EC_KEY_new_by_curve_name(NID_secp256k1);
  ret_error    = EC_KEY_generate_key(key_pair_obj);

  // Get private key
  priv_key      = (BIGNUM *)EC_KEY_get0_private_key(key_pair_obj);
  priv_key_char = BN_bn2hex(priv_key);

  // Get public key
  pub_key         = (EC_POINT *)EC_KEY_get0_public_key(key_pair_obj);
  secp256k1_group = EC_GROUP_new_by_curve_name(NID_secp256k1);
  pub_key_char    = EC_POINT_point2hex(secp256k1_group, pub_key, POINT_CONVERSION_COMPRESSED, nullptr);
  EC_GROUP_free(secp256k1_group);

  printf("Pivate key     : %s\n", priv_key_char);
  printf("Public key     : %s\n", pub_key_char);

  // Sign message
  signature_len = ECDSA_size(key_pair_obj); // the signature size depends on the key
  signature     = (uint8_t *) OPENSSL_malloc(signature_len);
  digest        = SHA256((const unsigned char *)message, strlen(message), buffer_digest);
  ret_error     = ECDSA_sign(0, (const uint8_t *)digest, SHA256_DIGEST_LENGTH, signature, &signature_len, key_pair_obj);

  printf("Message SHA256 : "); for(uint32_t i = 0U; i < SHA256_DIGEST_LENGTH; ++i) printf("%02x", digest   [i]); printf("\n");
  printf("Signature      : "); for(uint32_t i = 0U; i < signature_len       ; ++i) printf("%02x", signature[i]); printf("\n");

  // Verify the signature
  verification = ECDSA_verify(0, digest, SHA256_DIGEST_LENGTH, signature, signature_len, key_pair_obj);

  if (verification == 1)
  {
    printf("Verification   : successful\n");
  }
  else
  {
    printf("Verification   : NOT successful\n");
  }
  EC_KEY_free(key_pair_obj);

  // Double check process for correctness
  imported_key_pair = EC_KEY_new_by_curve_name(NID_secp256k1);
  curve_group       = EC_GROUP_new_by_curve_name(NID_secp256k1);
  public_point      = EC_POINT_new(curve_group);
  public_point      = EC_POINT_hex2point(curve_group, pub_key_char, public_point, nullptr);
  ret_error         = EC_KEY_set_public_key(imported_key_pair, public_point);
  EC_GROUP_free(curve_group);
  EC_POINT_free(public_point);
  free(pub_key_char);

  bn        = BN_new();
  char_read = BN_hex2bn(&bn, priv_key_char);
  ret_error = EC_KEY_set_private_key(imported_key_pair, bn);
  BN_clear_free(bn);
  free(priv_key_char);
        
  verification = ECDSA_verify(0, digest, SHA256_DIGEST_LENGTH, signature, signature_len, imported_key_pair);
  if (verification == 1)
  {
    printf("Re-Verification: successful\n");
  }
  else
  {
    printf("Re-Verification: NOT successful\n");
  }

  EC_KEY_free(imported_key_pair);

  OPENSSL_free(signature);
}
