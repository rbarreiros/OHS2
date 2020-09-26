/*
 * ohs_th_https.h
 *
 *  Created on: 6. 9. 2020
 *      Author: adam
 */

#ifndef OHS_TH_HTTPS_H_
#define OHS_TH_HTTPS_H_

#if OHS_HTTPS

#define WOLFSSL_STM32F4
#include "wolfssl_chibios.h"

#if !defined(WEB_THREAD_STACK_SIZE)
#define WEB_THREAD_STACK_SIZE           (16 * 1024)
#endif

#if !defined(WEB_THREAD_PORT)
#define WEB_THREAD_PORT                 443
#endif

#if !defined(WEB_THREAD_PRIORITY)
#define WEB_THREAD_PRIORITY             (LOWPRIO + 2)
#endif

#if !defined(WEB_MAX_PATH_SIZE)
#define WEB_MAX_PATH_SIZE               128
#endif

const unsigned char server_cert[] = {
  0x30, 0x82, 0x03, 0x10, 0x30, 0x82, 0x02, 0xb5, 0xa0, 0x03, 0x02, 0x01,
  0x02, 0x02, 0x09, 0x00, 0xef, 0x46, 0xc7, 0xa4, 0x9b, 0xbb, 0x60, 0xd3,
  0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02,
  0x30, 0x81, 0x8f, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06,
  0x13, 0x02, 0x55, 0x53, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04,
  0x08, 0x0c, 0x0a, 0x57, 0x61, 0x73, 0x68, 0x69, 0x6e, 0x67, 0x74, 0x6f,
  0x6e, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x07, 0x0c, 0x07,
  0x53, 0x65, 0x61, 0x74, 0x74, 0x6c, 0x65, 0x31, 0x10, 0x30, 0x0e, 0x06,
  0x03, 0x55, 0x04, 0x0a, 0x0c, 0x07, 0x45, 0x6c, 0x69, 0x70, 0x74, 0x69,
  0x63, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x0c, 0x03,
  0x45, 0x43, 0x43, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03,
  0x0c, 0x0f, 0x77, 0x77, 0x77, 0x2e, 0x77, 0x6f, 0x6c, 0x66, 0x73, 0x73,
  0x6c, 0x2e, 0x63, 0x6f, 0x6d, 0x31, 0x1f, 0x30, 0x1d, 0x06, 0x09, 0x2a,
  0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x01, 0x16, 0x10, 0x69, 0x6e,
  0x66, 0x6f, 0x40, 0x77, 0x6f, 0x6c, 0x66, 0x73, 0x73, 0x6c, 0x2e, 0x63,
  0x6f, 0x6d, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x36, 0x30, 0x38, 0x31, 0x31,
  0x32, 0x30, 0x30, 0x37, 0x33, 0x38, 0x5a, 0x17, 0x0d, 0x31, 0x39, 0x30,
  0x35, 0x30, 0x38, 0x32, 0x30, 0x30, 0x37, 0x33, 0x38, 0x5a, 0x30, 0x81,
  0x8f, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02,
  0x55, 0x53, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x08, 0x0c,
  0x0a, 0x57, 0x61, 0x73, 0x68, 0x69, 0x6e, 0x67, 0x74, 0x6f, 0x6e, 0x31,
  0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x07, 0x0c, 0x07, 0x53, 0x65,
  0x61, 0x74, 0x74, 0x6c, 0x65, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55,
  0x04, 0x0a, 0x0c, 0x07, 0x45, 0x6c, 0x69, 0x70, 0x74, 0x69, 0x63, 0x31,
  0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0b, 0x0c, 0x03, 0x45, 0x43,
  0x43, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x0f,
  0x77, 0x77, 0x77, 0x2e, 0x77, 0x6f, 0x6c, 0x66, 0x73, 0x73, 0x6c, 0x2e,
  0x63, 0x6f, 0x6d, 0x31, 0x1f, 0x30, 0x1d, 0x06, 0x09, 0x2a, 0x86, 0x48,
  0x86, 0xf7, 0x0d, 0x01, 0x09, 0x01, 0x16, 0x10, 0x69, 0x6e, 0x66, 0x6f,
  0x40, 0x77, 0x6f, 0x6c, 0x66, 0x73, 0x73, 0x6c, 0x2e, 0x63, 0x6f, 0x6d,
  0x30, 0x59, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x02,
  0x01, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03,
  0x42, 0x00, 0x04, 0xbb, 0x33, 0xac, 0x4c, 0x27, 0x50, 0x4a, 0xc6, 0x4a,
  0xa5, 0x04, 0xc3, 0x3c, 0xde, 0x9f, 0x36, 0xdb, 0x72, 0x2d, 0xce, 0x94,
  0xea, 0x2b, 0xfa, 0xcb, 0x20, 0x09, 0x39, 0x2c, 0x16, 0xe8, 0x61, 0x02,
  0xe9, 0xaf, 0x4d, 0xd3, 0x02, 0x93, 0x9a, 0x31, 0x5b, 0x97, 0x92, 0x21,
  0x7f, 0xf0, 0xcf, 0x18, 0xda, 0x91, 0x11, 0x02, 0x34, 0x86, 0xe8, 0x20,
  0x58, 0x33, 0x0b, 0x80, 0x34, 0x89, 0xd8, 0xa3, 0x81, 0xf7, 0x30, 0x81,
  0xf4, 0x30, 0x1d, 0x06, 0x03, 0x55, 0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14,
  0x5d, 0x5d, 0x26, 0xef, 0xac, 0x7e, 0x36, 0xf9, 0x9b, 0x76, 0x15, 0x2b,
  0x4a, 0x25, 0x02, 0x23, 0xef, 0xb2, 0x89, 0x30, 0x30, 0x81, 0xc4, 0x06,
  0x03, 0x55, 0x1d, 0x23, 0x04, 0x81, 0xbc, 0x30, 0x81, 0xb9, 0x80, 0x14,
  0x5d, 0x5d, 0x26, 0xef, 0xac, 0x7e, 0x36, 0xf9, 0x9b, 0x76, 0x15, 0x2b,
  0x4a, 0x25, 0x02, 0x23, 0xef, 0xb2, 0x89, 0x30, 0xa1, 0x81, 0x95, 0xa4,
  0x81, 0x92, 0x30, 0x81, 0x8f, 0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55,
  0x04, 0x06, 0x13, 0x02, 0x55, 0x53, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03,
  0x55, 0x04, 0x08, 0x0c, 0x0a, 0x57, 0x61, 0x73, 0x68, 0x69, 0x6e, 0x67,
  0x74, 0x6f, 0x6e, 0x31, 0x10, 0x30, 0x0e, 0x06, 0x03, 0x55, 0x04, 0x07,
  0x0c, 0x07, 0x53, 0x65, 0x61, 0x74, 0x74, 0x6c, 0x65, 0x31, 0x10, 0x30,
  0x0e, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x07, 0x45, 0x6c, 0x69, 0x70,
  0x74, 0x69, 0x63, 0x31, 0x0c, 0x30, 0x0a, 0x06, 0x03, 0x55, 0x04, 0x0b,
  0x0c, 0x03, 0x45, 0x43, 0x43, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03, 0x55,
  0x04, 0x03, 0x0c, 0x0f, 0x77, 0x77, 0x77, 0x2e, 0x77, 0x6f, 0x6c, 0x66,
  0x73, 0x73, 0x6c, 0x2e, 0x63, 0x6f, 0x6d, 0x31, 0x1f, 0x30, 0x1d, 0x06,
  0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x01, 0x16, 0x10,
  0x69, 0x6e, 0x66, 0x6f, 0x40, 0x77, 0x6f, 0x6c, 0x66, 0x73, 0x73, 0x6c,
  0x2e, 0x63, 0x6f, 0x6d, 0x82, 0x09, 0x00, 0xef, 0x46, 0xc7, 0xa4, 0x9b,
  0xbb, 0x60, 0xd3, 0x30, 0x0c, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x04, 0x05,
  0x30, 0x03, 0x01, 0x01, 0xff, 0x30, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48,
  0xce, 0x3d, 0x04, 0x03, 0x02, 0x03, 0x49, 0x00, 0x30, 0x46, 0x02, 0x21,
  0x00, 0xf1, 0xd0, 0xa6, 0x3e, 0x83, 0x33, 0x24, 0xd1, 0x7a, 0x05, 0x5f,
  0x1e, 0x0e, 0xbd, 0x7d, 0x6b, 0x33, 0xe9, 0xf2, 0x86, 0xf3, 0xf3, 0x3d,
  0xa9, 0xef, 0x6a, 0x87, 0x31, 0xb3, 0xb7, 0x7e, 0x50, 0x02, 0x21, 0x00,
  0xf0, 0x60, 0xdd, 0xce, 0xa2, 0xdb, 0x56, 0xec, 0xd9, 0xf4, 0xe4, 0xe3,
  0x25, 0xd4, 0xb0, 0xc9, 0x25, 0x7d, 0xca, 0x7a, 0x5d, 0xba, 0xc4, 0xb2,
  0xf6, 0x7d, 0x04, 0xc7, 0xbd, 0x62, 0xc9, 0x20
};
unsigned int server_cert_len = 788;
const unsigned char server_key[] = {
  0x30, 0x77, 0x02, 0x01, 0x01, 0x04, 0x20, 0x45, 0xb6, 0x69, 0x02, 0x73,
  0x9c, 0x6c, 0x85, 0xa1, 0x38, 0x5b, 0x72, 0xe8, 0xe8, 0xc7, 0xac, 0xc4,
  0x03, 0x8d, 0x53, 0x35, 0x04, 0xfa, 0x6c, 0x28, 0xdc, 0x34, 0x8d, 0xe1,
  0xa8, 0x09, 0x8c, 0xa0, 0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d,
  0x03, 0x01, 0x07, 0xa1, 0x44, 0x03, 0x42, 0x00, 0x04, 0xbb, 0x33, 0xac,
  0x4c, 0x27, 0x50, 0x4a, 0xc6, 0x4a, 0xa5, 0x04, 0xc3, 0x3c, 0xde, 0x9f,
  0x36, 0xdb, 0x72, 0x2d, 0xce, 0x94, 0xea, 0x2b, 0xfa, 0xcb, 0x20, 0x09,
  0x39, 0x2c, 0x16, 0xe8, 0x61, 0x02, 0xe9, 0xaf, 0x4d, 0xd3, 0x02, 0x93,
  0x9a, 0x31, 0x5b, 0x97, 0x92, 0x21, 0x7f, 0xf0, 0xcf, 0x18, 0xda, 0x91,
  0x11, 0x02, 0x34, 0x86, 0xe8, 0x20, 0x58, 0x33, 0x0b, 0x80, 0x34, 0x89,
  0xd8
};
unsigned int server_key_len = 121;


static char url_buffer[WEB_MAX_PATH_SIZE];
unsigned int server_cert_len;
unsigned int server_key_len;

#define HEXTOI(x) (isdigit(x) ? (x) - '0' : (x) - 'a' + 10)

/**
 * @brief   Decodes an URL sting.
 * @note    The string is terminated by a zero or a separator.
 *
 * @param[in] url       encoded URL string
 * @param[out] buf      buffer for the processed string
 * @param[in] max       max number of chars to copy into the buffer
 * @return              The conversion status.
 * @retval false        string converted.
 * @retval true         the string was not valid or the buffer overflowed
 *
 * @notapi
 */
static bool decode_url(const char *url, char *buf, size_t max) {

  while (true) {
    int h, l;
    unsigned c = *url++;

    switch (c) {
    case 0:
    case '\r':
    case '\n':
    case '\t':
    case ' ':
    case '?':
      *buf = 0;
      return false;
    case '.':
      if (max <= 1)
        return true;

      h = *(url + 1);
      if (h == '.')
        return true;

      break;
    case '%':
      if (max <= 1)
        return true;

      h = tolower((int)*url++);
      if (h == 0)
        return true;
      if (!isxdigit(h))
        return true;

      l = tolower((int)*url++);
      if (l == 0)
        return true;
      if (!isxdigit(l))
        return true;

      c = (char)((HEXTOI(h) << 4) | HEXTOI(l));
      break;
    default:
      if (max <= 1)
        return true;

      if (!isalnum(c) && (c != '_') && (c != '-') && (c != '+') &&
          (c != '/'))
        return true;

      break;
    }

    *buf++ = c;
    max--;
  }
}


#define MAX_HTTPREQ_SIZE 256
static const char http_html_hdr[] = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n";
static const char http_index_html[] = "<html><head><title>Congrats!</title></head><body><h1>Welcome to chibiOS HTTPS server!</h1><p>Powered by LwIP + WolfSSL</body></html>";

static char inbuf[MAX_HTTPREQ_SIZE];
static void https_server_serve(sslconn *sc)
{
  int ret;

  /* Read the data from the port, blocking if nothing yet there.
     We assume the request (the part we care about) is in one netbuf.*/
  ret = wolfSSL_read(sc->ssl, inbuf, MAX_HTTPREQ_SIZE);
  if (ret >= 5 &&
          inbuf[0] == 'G' &&
          inbuf[1] == 'E' &&
          inbuf[2] == 'T' &&
          inbuf[3] == ' ' &&
          inbuf[4] == '/') {

      if (decode_url(inbuf + 4, url_buffer, WEB_MAX_PATH_SIZE)) {
          /* Invalid URL handling.*/
          return;
      }

      /* Send the HTML header
       * subtract 1 from the size, since we dont send the \0 in the string
       * NETCONN_NOCOPY: our data is const static, so no need to copy it
       */
      wolfSSL_write(sc->ssl, http_html_hdr, sizeof(http_html_hdr)-1);

      /* Send our HTML page */
      wolfSSL_write(sc->ssl, http_index_html, sizeof(http_index_html)-1);
  }
}

/**
 * @brief   Stack area for the http thread.
 */
THD_WORKING_AREA(wa_https_server, WEB_THREAD_STACK_SIZE);

/**
 * @brssl   HTTPS server thread.
 */
THD_FUNCTION(https_server, p) {
  sslconn *sc, *newsc;
  (void)p;
  chRegSetThreadName("https");

  /* Initialize wolfSSL */
  wolfSSL_Init();

  /* Create a new SSL connection handle */
  sc = sslconn_new(NETCONN_TCP, wolfTLSv1_2_server_method());
  if (!sc) {
      while(1) {}
  }

  /* Load certificate file for the HTTPS server */
  if (wolfSSL_CTX_use_certificate_buffer(sc->ctx, server_cert,
              server_cert_len, SSL_FILETYPE_ASN1 ) != SSL_SUCCESS)
      while(1) {}

  /* Load the private key */
  if (wolfSSL_CTX_use_PrivateKey_buffer(sc->ctx, server_key,
              server_key_len, SSL_FILETYPE_ASN1 ) != SSL_SUCCESS)
      while(1) {}

  /* Bind to port 443 (HTTPS) with default IP address */
  netconn_bind(sc->conn, NULL, WEB_THREAD_PORT);

  /* Put the connection into LISTEN state */
  netconn_listen(sc->conn);

  /* Goes to the final priority after initialization.*/
  chThdSetPriority(WEB_THREAD_PRIORITY);

  /* Listening loop */
  while (true) {
    newsc = sslconn_accept(sc);
    if (!newsc) {
        chThdSleepMilliseconds(100);
        continue;
    }
    /* New connection: a new SSL connector is spawned */
    https_server_serve(newsc);
    umm_info(&ohsUmmHeap[0], true);
    sslconn_close(newsc);
  }
}

#endif


#endif /* OHS_TH_HTTPS_H_ */
