/*
 * ohs_conf.h
 *
 *  Created on: 26. 9. 2018
 *      Author: Adam
 */

#ifndef OHS_CONF_H_
#define OHS_CONF_H_

#if STM32_BKPRAM_ENABLE == STM32_NO_INIT
#error "In mcuconf.h STM32_BKPRAM_ENABLE must be TRUE!"
#endif

#define OHS_MAJOR        1
#define OHS_MINOR        1

#define BACKUP_SRAM_SIZE 0x1000 // 4kB SRAM size
#define BACKUP_RTC_SIZE  80     // 80 bytes

#define ALARM_ZONES      30     // Maximum zones
#define ALARM_GROUPS     8      // Maximum groups
#define HW_ZONES         11     // # of hardware zones on gateway
#define CONTACTS_SIZE    10     // Maximum contacts
#define KEYS_SIZE        20     // Maximum keys
#define KEY_LENGTH       8      //
#define NAME_LENGTH      16     //
#define PHONE_LENGTH     14     //
#define EMAIL_LENGTH     30     //

#define ALARM_PIR        3400   //(3380 = 15.2V)
#define ALARM_PIR_LOW    3050
#define ALARM_PIR_HI     3650
#define ALARM_OK         1850   //(1850 = 15.2V)
#define ALARM_OK_LOW     1500
#define ALARM_OK_HI      2100
#define ALARM_TAMPER     0

#define RADIO_UNIT_OFFSET 15
#define REGISTRATION_SIZE 22

#define NOT_SET          "not set"

#define NODE_SIZE        10     // Number of nodes

#define LOGGER_MSG_LENGTH 11

/**
 * @name    Node commands
 */
#define NODE_CMD_ACK          0
#define NODE_CMD_REGISTRATION 1
#define NODE_CMD_PING         2
#define NODE_CMD_PONG         3

#define NODE_CMD_ARM          10
#define NODE_CMD_AUTH_0       11
#define NODE_CMD_AUTH_1       12
#define NODE_CMD_AUTH_2       13
#define NODE_CMD_AUTH_3       14
#define NODE_CMD_AUTH_4       15
#define NODE_CMD_DISARM       16


/*
 * Bit wise macros for various settings
 */
#define GET_CONF_ZONE_ENABLED(x)     ((x) & 0b1)
#define GET_CONF_ZONE_GROUP(x)       ((x >> 1U) & 0b1111)
#define GET_CONF_ZONE_AUTH_TIME(x)   ((x >> 5U) & 0b11)
#define GET_CONF_ZONE_ARM_HOME(x)    ((x >> 7U) & 0b1)
#define GET_CONF_ZONE_STILL_OPEN(x)  ((x >> 8U) & 0b1)
#define GET_CONF_ZONE_PIR_AS_TMP(x)  ((x >> 9U) & 0b1)
#define GET_CONF_ZONE_IS_BATTERY(x)  ((x >> 11U) & 0b1)
#define GET_CONF_ZONE_IS_REMOTE(x)   ((x >> 12U) & 0b1)
#define GET_CONF_ZONE_IS_PRESENT(x)  ((x >> 14U) & 0b1)
#define GET_CONF_ZONE_TYPE(x)        ((x >> 15U) & 0b1)
#define SET_CONF_ZONE_ENABLED(x)     x |= 1
#define SET_CONF_ZONE_GROUP(x,y)     x = (((x)&(0b1111111111100001))|(((y & 0b1111) << 1U)&(0b0000000000011110)))
#define SET_CONF_ZONE_AUTH_TIME(x,y) x = (((x)&(0b1111111110011111))|(((y & 0b11) << 5U)&(0b0000000001100000)))
#define SET_CONF_ZONE_ARM_HOME(x)    x |= (1 << 7U)
#define SET_CONF_ZONE_STILL_OPEN(x)  x |= (1 << 8U)
#define SET_CONF_ZONE_PIR_AS_TMP(x)  x |= (1 << 9U)
#define SET_CONF_ZONE_IS_BATTERY(x)  x |= (1 << 11U)
#define SET_CONF_ZONE_IS_REMOTE(x)   x |= (1 << 12U)
#define SET_CONF_ZONE_IS_PRESENT(x)  x |= (1 << 14U)
#define SET_CONF_ZONE_TYPE(x)        x |= (1 << 15U)
#define CLEAR_CONF_ZONE_ENABLED(x)     x &= ~1
#define CLEAR_CONF_ZONE_ARM_HOME(x)    x &= ~(1 << 7U)
#define CLEAR_CONF_ZONE_STILL_OPEN(x)  x &= ~(1 << 8U)
#define CLEAR_CONF_ZONE_PIR_AS_TMP(x)  x &= ~(1 << 9U)
#define CLEAR_CONF_ZONE_IS_BATTERY(x)  x &= ~(1 << 11U)
#define CLEAR_CONF_ZONE_IS_REMOTE(x)   x &= ~(1 << 12U)
#define CLEAR_CONF_ZONE_IS_PRESENT(x)  x &= ~(1 << 14U)
#define CLEAR_CONF_ZONE_TYPE(x)        x &= ~(1 << 15U)

#define GET_CONF_GROUP_ENABLED(x)      ((x) & 0b1)
#define GET_CONF_GROUP_TAMPER2(x)      ((x >> 1U) & 0b1)
#define GET_CONF_GROUP_TAMPER1(x)      ((x >> 2U) & 0b1)
#define GET_CONF_GROUP_PIR2(x)         ((x >> 3U) & 0b1)
#define GET_CONF_GROUP_PIR1(x)         ((x >> 4U) & 0b1)
#define GET_CONF_GROUP_AUTO_ARM(x)     ((x >> 5U) & 0b1)
#define GET_CONF_GROUP_MQTT_PUB(x)     ((x >> 7U) & 0b1)
#define GET_CONF_GROUP_ARM_CHAIN(x)    ((x >> 8U) & 0b1111)
#define GET_CONF_GROUP_DISARM_CHAIN(x) ((x >> 12U) & 0b1111)
#define SET_CONF_GROUP_ENABLED(x)        x |= 1
#define SET_CONF_GROUP_TAMPER2(x)        x |= (1 << 1U)
#define SET_CONF_GROUP_TAMPER1(x)        x |= (1 << 2U)
#define SET_CONF_GROUP_PIR2(x)           x |= (1 << 3U)
#define SET_CONF_GROUP_PIR1(x)           x |= (1 << 4U)
#define SET_CONF_GROUP_AUTO_ARM(x)       x |= (1 << 5U)
#define SET_CONF_GROUP_MQTT_PUB(x)       x |= (1 << 7U)
#define SET_CONF_GROUP_ARM_CHAIN(x,y)    x = (((x)&(0b1111000011111111))|(((y & 0b1111) << 8U)&(0b0000111100000000)))
#define SET_CONF_GROUP_DISARM_CHAIN(x,y) x = (((x)&(0b0000111111111111))|(((y & 0b1111) << 12U)&(0b1111000000000000)))
#define CLEAR_CONF_GROUP_ENABLED(x)      x &= ~1
#define CLEAR_CONF_GROUP_TAMPER2(x)      x &= ~(1 << 1U)
#define CLEAR_CONF_GROUP_TAMPER1(x)      x &= ~(1 << 2U)
#define CLEAR_CONF_GROUP_PIR2(x)         x &= ~(1 << 3U)
#define CLEAR_CONF_GROUP_PIR1(x)         x &= ~(1 << 4U)
#define CLEAR_CONF_GROUP_AUTO_ARM(x)     x &= ~(1 << 5U)
#define CLEAR_CONF_GROUP_MQTT_PUB(x)     x &= ~(1 << 7U)

#define GET_CONF_CONTACT_ENABLED(x)     ((x) & 0b1)
#define GET_CONF_CONTACT_GROUP(x)       ((x >> 1U) & 0b1111)
#define GET_CONF_CONTACT_IS_GLOBAL(x)   ((x >> 5U) & 0b1)
#define SET_CONF_CONTACT_ENABLED(x)     x |= 1
#define SET_CONF_CONTACT_GROUP(x,y)     x = (((x)&(0b11100001))|(((y & 0b1111) << 1U)&(0b00011110)))
#define SET_CONF_CONTACT_IS_GLOBAL(x)   x |= (1 << 5U)
#define CLEAR_CONF_CONTACT_ENABLED(x)   x &= ~1
#define CLEAR_CONF_CONTACT_IS_GLOBAL(x) x &= ~(1 << 5U)


#define GET_CONF_KEY_ENABLED(x)     ((x) & 0b1)
#define GET_CONF_KEY_GROUP(x)       ((x >> 1U) & 0b1111)
#define GET_CONF_KEY_IS_GLOBAL(x)   ((x >> 5U) & 0b1)
#define SET_CONF_KEY_ENABLED(x)     x |= 1
#define SET_CONF_KEY_GROUP(x,y)     x = (((x)&(0b11100001))|(((y & 0b1111) << 1U)&(0b00011110)))
#define SET_CONF_KEY_IS_GLOBAL(x)   x |= (1 << 5U)
#define CLEAR_CONF_KEY_ENABLED(x)   x &= ~1
#define CLEAR_CONF_KEY_IS_GLOBAL(x) x &= ~(1 << 5U)

#define GET_ZONE_ALARM(x)     ((x >> 1U) & 0b1)
#define GET_ZONE_ERROR(x)     ((x >> 5U) & 0b1)
#define GET_ZONE_QUEUED(x)    ((x >> 6U) & 0b1)
#define GET_ZONE_FULL_FIFO(x) ((x >> 7U) & 0b1)
#define SET_ZONE_ALARM(x)     x |= (1 << 1U)
#define SET_ZONE_ERROR(x)     x |= (1 << 5U)
#define SET_ZONE_QUEUED(x)    x |= (1 << 6U)
#define SET_ZONE_FULL_FIFO(x) x |= (1 << 7U)
#define CLEAR_ZONE_ALARM(x)     x &= ~(1 << 1U)
#define CLEAR_ZONE_ERROR(x)     x &= ~(1 << 5U)
#define CLEAR_ZONE_QUEUED(x)    x &= ~(1 << 6U)
#define CLEAR_ZONE_FULL_FIFO(x) x &= ~(1 << 7U)

#define GET_GROUP_ARMED(x)         ((x) & 0b1)
#define GET_GROUP_ALARM(x)         ((x >> 1U) & 0b1)
#define GET_GROUP_WAIT_ATUH(x)     ((x >> 2U) & 0b1)
#define GET_GROUP_ARMED_HOME(x)    ((x >> 3U) & 0b1)
#define GET_GROUP_DISABLED_FLAG(x) ((x >> 7U) & 0b1)
#define SET_GROUP_ARMED(x)         x |= 1
#define SET_GROUP_ALARM(x)         x |= (1 << 1U)
#define SET_GROUP_WAIT_ATUH(x)     x |= (1 << 2U)
#define SET_GROUP_ARMED_HOME(x)    x |= (1 << 3U)
#define SET_GROUP_DISABLED_FLAG(x) x |= (1 << 7U)
#define CLEAR_GROUP_ARMED(x)         x &= ~1
#define CLEAR_GROUP_ALARM(x)         x &= ~(1 << 1U)
#define CLEAR_GROUP_WAIT_ATUH(x)     x &= ~(1 << 2U)
#define CLEAR_GROUP_ARMED_HOME(x)    x &= ~(1 << 3U)
#define CLEAR_GROUP_DISABLED_FLAG(x) x &= ~(1 << 7U)

#define GET_NODE_ENABLED(x)  ((x) & 0b1)
#define GET_NODE_GROUP(x)    ((x >> 1U) & 0b1111)
#define GET_NODE_BATT_LOW(x) ((x >> 5U) & 0b1)
#define GET_NODE_MQTT_PUB(x) ((x >> 7U) & 0b1)
#define SET_NODE_ENABLED(x)  x |= 1
#define SET_NODE_GROUP(x,y)  x = (((x)&(0b1111111111100001))|(((y & 0b1111) << 1U)&(0b0000000000011110)))
#define SET_NODE_BATT_LOW(x) x |= (1 << 5U)
#define SET_NODE_MQTT_PUB(x) x |= (1 << 7U)
#define CLEAR_NODE_ENABLED(x)  x &= ~1
#define CLEAR_NODE_BATT_LOW(x) x &= ~(1 << 5U)
#define CLEAR_NODE_MQTT_PUB(x) x &= ~(1 << 7U)

// Global vars
char lastKey[KEY_LENGTH];
char tmpLog[LOGGER_MSG_LENGTH]; // Temporary logger string
// RTC related
static RTCDateTime timespec;
time_t startTime;  // OHS start timestamp variable

// time_t conversion
union time_tag {
  char   ch[4];
  time_t val;
} timeConv;

// Zones alarm events
#define ALARMEVENT_FIFO_SIZE 10
typedef struct {
  uint16_t zone;
  char     type;
} alarmEvent_t;

// Logger events
#define LOGGER_FIFO_SIZE 20
typedef struct {
  time_t timestamp;
  char   text[LOGGER_MSG_LENGTH];
} logger_t;

// Alert events
#define ALERT_FIFO_SIZE 5
typedef struct {
  char    text[LOGGER_MSG_LENGTH];
  uint8_t flag;
} alert_t;


// Registration events
#define REG_FIFO_SIZE 6
#define REG_PACKET_HEADER_SIZE 5
#define REG_PACKET_SIZE 21
typedef struct {
  char     type;
  uint8_t  address;
  char     function;
  uint8_t  number;
  uint16_t setting;
  char     name[NAME_LENGTH];
  uint16_t dummyAlign;
} registration_t;

// Sensor events
#define SENSOR_FIFO_SIZE 10
typedef struct {
  char    type;     // = 'S';
  uint8_t address;  // = 0;
  char    function; // = ' ';
  uint8_t number;   // = 0;
  float   value;    // = 0.0;
} sensor_t;

// Alerts
// Logger keeps info about this as flag, so max value is sizeof(uint8_t)
#define ALERT_TYPE_SIZE 3
typedef struct {
  char    name[6];
  uint8_t number;
} alertType_t;
const alertType_t alertType[ALERT_TYPE_SIZE] = {
  { "SMS", 0 },
  { "Email", 1 },
  { "Page", 2 }
};
#define ALERT_SIZE sizeof(alertDef)/sizeof(alertDef[0])
//#define ALERT_SIZE 2 // List of alerts max is sizeof(uint32_t)
// Logger message text to match alert
const char alertDef[][3] = {
  "SS",
  "SA"
};

/*
 * Mailboxes
 */
static msg_t        alarmEvent_mb_buffer[ALARMEVENT_FIFO_SIZE];
static MAILBOX_DECL(alarmEvent_mb, alarmEvent_mb_buffer, ALARMEVENT_FIFO_SIZE);

static msg_t        logger_mb_buffer[LOGGER_FIFO_SIZE];
static MAILBOX_DECL(logger_mb, logger_mb_buffer, LOGGER_FIFO_SIZE);

static msg_t        registration_mb_buffer[REG_FIFO_SIZE];
static MAILBOX_DECL(registration_mb, registration_mb_buffer, REG_FIFO_SIZE);

static msg_t        sensor_mb_buffer[SENSOR_FIFO_SIZE];
static MAILBOX_DECL(sensor_mb, sensor_mb_buffer, SENSOR_FIFO_SIZE);

static msg_t        alert_mb_buffer[ALERT_FIFO_SIZE];
static MAILBOX_DECL(alert_mb, alert_mb_buffer, ALERT_FIFO_SIZE);
/*
 * Pools
 */
static alarmEvent_t   alarmEvent_pool_queue[ALARMEVENT_FIFO_SIZE];
static MEMORYPOOL_DECL(alarmEvent_pool, sizeof(alarmEvent_t), PORT_NATURAL_ALIGN, NULL);

static logger_t       logger_pool_queue[LOGGER_FIFO_SIZE];
static MEMORYPOOL_DECL(logger_pool, sizeof(logger_t), PORT_NATURAL_ALIGN, NULL);

static registration_t registration_pool_queue[REG_FIFO_SIZE];
static MEMORYPOOL_DECL(registration_pool, sizeof(registration_t), PORT_NATURAL_ALIGN, NULL);

static sensor_t       sensor_pool_queue[SENSOR_FIFO_SIZE];
static MEMORYPOOL_DECL(sensor_pool, sizeof(sensor_t), PORT_NATURAL_ALIGN, NULL);

static alert_t        alert_pool_queue[ALERT_FIFO_SIZE];
static MEMORYPOOL_DECL(alert_pool, sizeof(alert_t), PORT_NATURAL_ALIGN, NULL);

//static node_t          node_pool_queue[NODE_SIZE];
//static MEMORYPOOL_DECL(node_pool, sizeof(node_t), PORT_NATURAL_ALIGN, NULL);


// Configuration struct
typedef struct {
  uint8_t  versionMajor;
  uint8_t  versionMinor;

  uint16_t logOffset;
  uint8_t  armDelay;
  char     dateTimeFormat[NAME_LENGTH];

  uint16_t zone[ALARM_ZONES];
  char     zoneName[ALARM_ZONES][NAME_LENGTH];
  uint8_t  zoneAddress[ALARM_ZONES-HW_ZONES];          // Remote zone address

  uint16_t group[ALARM_GROUPS];
  char     groupName[ALARM_GROUPS][NAME_LENGTH];

  uint8_t  contact[CONTACTS_SIZE];
  char     contactName[CONTACTS_SIZE][NAME_LENGTH];
  char     contactPhone[CONTACTS_SIZE][PHONE_LENGTH];
  char     contactEmail[CONTACTS_SIZE][EMAIL_LENGTH];

  uint8_t  keySetting[KEYS_SIZE];
  char     keyValue[KEYS_SIZE][KEY_LENGTH];
  //char     keyName[KEYS_SIZE][NAME_LENGTH];
  uint8_t  keyContact[KEYS_SIZE];

  uint32_t alert[3];

  char     NTPAddress[32];
  uint8_t  time_std_week;   //First, Second, Third, Fourth, or Last week of the month
  uint8_t  time_std_dow;    //day of week, 1=Sun, 2=Mon, ... 7=Sat
  uint8_t  time_std_month;  //1=Jan, 2=Feb, ... 12=Dec
  uint8_t  time_std_hour;   //0-23
  int16_t  time_std_offset; //offset from UTC in minutes

  uint8_t  time_dst_week;   //First, Second, Third, Fourth, or Last week of the month
  uint8_t  time_dst_dow;    //day of week, 1=Sun, 2=Mon, ... 7=Sat
  uint8_t  time_dst_month;  //1=Jan, 2=Feb, ... 12=Dec
  uint8_t  time_dst_hour;   //0-23
  int16_t  time_dst_offset; //offset from UTC in minutes
} config_t;
config_t conf;

// Group runtime variables
typedef struct {
  uint8_t setting;
  uint8_t armDelay;
} group_t;
group_t group[ALARM_GROUPS];

// Zone runtime variables
typedef struct {
  time_t  lastPIR;
  time_t  lastOK;
  char    lastEvent;
  uint8_t setting;
} zone_t;
zone_t zone[ALARM_ZONES];

// Flags runtime variables
typedef struct {
  uint16_t flags;
} flags_t;
flags_t flags;

// Dynamic nodes
typedef struct {
  char    type;    //= 'K/S/I';
  uint8_t address; //= 0;
  char    function;//= ' ';
  uint8_t number;  //= 0;
   //                    |- MQTT publish
   //                    ||- Free
   //                    |||- Battery low flag, for battery type node
   //                    |||||||- Group number
   //                    |||||||- 0 .. 15
   //                    |||||||-
   //                    |||||||-
   //                    ||||||||-  Enabled
   //                    76543210
  uint16_t setting;// = B00011110;  // 2 bytes to store also zone setting
  float    value;  // = 0;
  time_t last_OK;// = 0;
  uint8_t  queue;  //   = 255; // No queue
  char name[NAME_LENGTH]; // = "";
} node_t;
node_t node[NODE_SIZE] = {{0}};

// Set default to runtime structs
void initRuntimeGroups(void){
  for(uint8_t i = 0; i < ALARM_GROUPS; i++) {
  //                      |- Disabled group log once flag
  //                      ||- Free
  //                      |||- Free
  //                      ||||- Free
  //                      |||||- Armed Home
  //                      ||||||-  Waiting for authorization
  //                      |||||||-  Alarm
  //                      ||||||||-  Armed
  //                      76543210
    group[i].setting  = 0b00000000;
    group[i].armDelay = 0;
  }
}
void initRuntimeZones(void){
  for(uint8_t i = 0; i < ALARM_ZONES; i++) {
    zone[i].lastPIR   = startTime;
    zone[i].lastOK    = startTime;
    zone[i].lastEvent = 'N';
    //                     |- Full FIFO queue flag
    //                     ||- Message queue
    //                     |||- Error flag, for remote zone
    //                     ||||- Free
    //                     |||||- Free
    //                     ||||||- Free
    //                     |||||||- Alarm
    //                     ||||||||- Free
    //                     76543210
    zone[i].setting    = 0b00000000;
  }
}


/*
 * SRAM/RTC backup related functions
 */
// Write to backup SRAM
int16_t writeToBkpSRAM(uint8_t *data, uint16_t size, uint16_t offset){
  if (size + offset >= BACKUP_SRAM_SIZE) osalSysHalt("SRAM out of region"); // Data out of BACKUP_SRAM_SIZE region
  uint16_t i = 0;
  uint8_t *baseAddress = (uint8_t *) BKPSRAM_BASE;
  for(i = 0; i < size; i++) {
    *(baseAddress + offset + i) = *(data + i);
  }
  return i;
}
// Read from backup SRAM
int16_t readFromBkpSRAM(uint8_t *data, uint16_t size, uint16_t offset){
  if (size + offset >= BACKUP_SRAM_SIZE) osalSysHalt("SRAM out of region");; // Data out of BACKUP_SRAM_SIZE region
  uint16_t i = 0;
  uint8_t *baseAddress = (uint8_t *) BKPSRAM_BASE;
  for(i = 0; i < size; i++) {
    *(data + i) = *(baseAddress + offset + i);
  }
  return i;
}

// Write to backup RTC
int16_t writeToBkpRTC(uint8_t *data, uint8_t size, uint8_t offset){
  if (size + offset >= BACKUP_RTC_SIZE) osalSysHalt("RTC out of region"); // Data out of BACKUP_RTC_SIZE region
  if (offset % 4) osalSysHalt("RCT misaligned");                          // Offset is not aligned to to unint32_t registers
  uint8_t i = 0;
  volatile uint32_t *RTCBaseAddress = &(RTC->BKP0R);
  uint32_t tmp = 0;
  for(i = 0; i < size; i++) {
    tmp |= (*(data + i) << ((i % 4)*8));
    if (((i % 4) == 3) || ((i + 1) == size)) {
      *(RTCBaseAddress + offset + (i/4)) = tmp;
      tmp = 0;
    }
  }
  return i;
}
// Read from backup RTC
int16_t readFromBkpRTC(uint8_t *data, uint8_t size, uint8_t offset){
  if (size + offset >= BACKUP_RTC_SIZE) osalSysHalt("RTC out of region"); // Data out of BACKUP_RTC_SIZE region
  if (offset % 4) osalSysHalt("RCT misaligned");                          // Offset is not aligned to to unint32_t registers
  uint8_t i = 0;
  volatile uint32_t *RTCBaseAddress = &(RTC->BKP0R);
  uint32_t tmp = 0;
  for(i = 0; i < size; i++) {
    if ((i % 4) == 0) { tmp = *(RTCBaseAddress + offset + (i/4)); }
    *(data + i) = (tmp >> ((i % 4)*8)) & 0xFF;
  }
  return i;
}

// Set conf default values
void setConfDefault(void){
  conf.versionMajor   = OHS_MAJOR;
  conf.versionMinor   = OHS_MINOR;
  conf.logOffset      = 0;
  conf.armDelay       = 20;
  strcpy(conf.dateTimeFormat, "%T %a %F");

  for(uint8_t i = 0; i < ALARM_ZONES; i++) {
    // Zones setup
    //                    |- Digital 0/ Analog 1
    //                    ||- Present - connected
    //                    |||- ~ Free ~
    //                    ||||- Remote zone
    //                    |||||- Battery powered zone, they don't send OK, only PIR or Tamper.
    //                    ||||||- Free
    //                    |||||||- PIR as Tamper
    //                    ||||||||- Still open alarm
    //                    ||||||||         |- Arm Home zone
    //                    ||||||||         |||- Auth time
    //                    ||||||||         |||- 0-3x the default time
    //                    ||||||||         |||||||- Group number
    //                    ||||||||         |||||||- 0 .. 15
    //                    ||||||||         |||||||-
    //                    ||||||||         |||||||-
    //                    ||||||||         ||||||||-  Enabled
    //                    54321098         76543210
    switch(i){
      case  0 ...  9:
         conf.zone[i] = 0b11000000 << 8 | 0b00011110; // Analog sensor
        break;
      case  10      :
         conf.zone[i] = 0b01000010 << 8 | 0b00011110; // Tamper
        break;
      default:
         conf.zone[i] = 0b00000000 << 8 | 0b00011110; // Other zones
         conf.zoneAddress[i-HW_ZONES] = 0;
        break;
    }
    //strcpy(conf.zoneName[i], NOT_SET);
    memset(&conf.zoneName[i][0], 0x00, NAME_LENGTH);
  }

  for(uint8_t i = 0; i < ALARM_GROUPS; i++) {
    //                  ||||- disarm chain
    //                  ||||
    //                  ||||
    //                  ||||
    //                  ||||||||- arm chain
    //                  ||||||||
    //                  ||||||||
    //                  ||||||||
    //                  ||||||||         |- MQTT publish
    //                  ||||||||         ||- Free
    //                  ||||||||         |||- Auto arm
    //                  ||||||||         ||||- PIR signal output 1
    //                  ||||||||         |||||- PIR signal output 2
    //                  ||||||||         ||||||-  Tamper signal output 1
    //                  ||||||||         |||||||-  Tamper signal output 2
    //                  ||||||||         ||||||||-  Enabled
    //                  54321098         76543210
    conf.group[i] = i << 12 | i << 8 | 0b00000000;
    //strcpy(conf.groupName[i], NOT_SET);
    memset(&conf.groupName[i][0], 0x00, NAME_LENGTH);
  }

  for(uint8_t i = 0; i < CONTACTS_SIZE; i++) {
    // group 16 and disabled
    conf.contact[i] = 0b00011110;
    memset(&conf.contactName[i][0], 0x00, NAME_LENGTH);
    memset(&conf.contactPhone[i][0], 0x00, PHONE_LENGTH);
    memset(&conf.contactEmail[i][0], 0x00, EMAIL_LENGTH);
    //strcpy(conf.contactName[i], NOT_SET);
    //strcpy(conf.contactPhone[i], NOT_SET);
    //strcpy(conf.contactEmail[i], NOT_SET);
  }

  for(uint8_t i = 0; i < KEYS_SIZE; i++) {
    // group 16 and disabled
    conf.keySetting[i] = 0b00011110;
    //strcpy(conf.keyName[i], NOT_SET);
    memset(&conf.keyValue[i][0], 0xFF, KEY_LENGTH);  // Set key value to FF
    conf.keyContact[i] = 255;
  }

      conf.keySetting[0] = 0b00100001;
      conf.keyValue[0][0] = 0x01;
      conf.keyValue[0][1] = 0x77;
      conf.keyValue[0][2] = 0x39;
      conf.keyValue[0][3] = 0x5A;
      conf.keyValue[0][4] = 0x01;
      conf.keyValue[0][5] = 0x00;
      conf.keyValue[0][6] = 0x00;
      conf.keyValue[0][7] = 0x3F;

  for(uint8_t i = 0; i < ALERT_TYPE_SIZE; i++) {
    conf.alert[i] = 0b11111111;
  }

  strcpy(conf.NTPAddress, "time.google.com");
  conf.time_std_week = 0;     //First, Second, Third, Fourth, or Last week of the month
  conf.time_std_dow = 0;      //day of week, 0=Sun, 1=Mon, ... 6=Sat
  conf.time_std_month = 10;   //1=Jan, 2=Feb, ... 12=Dec
  conf.time_std_hour = 3;     //0-23
  conf.time_std_offset = 60;  //offset from UTC in minutes
  conf.time_dst_week = 0;     //First, Second, Third, Fourth, or Last week of the month
  conf.time_dst_dow = 0;      //day of week, 0=Sun, 1=Mon, ... 6=Sat
  conf.time_dst_month = 3;    //1=Jan, 2=Feb, ... 12=Dec
  conf.time_dst_hour = 2;     //0-23
  conf.time_dst_offset = 120; //offset from UTC in minutes
}

//Year = 20**
//1=First,2=Second,3=Third,4=Fourth, or 0=Last week of the month
//day of week, 0=Sun, 1=Mon, ... 6=Sat
//1=Jan, 2=Feb, ... 12=Dec
//0-23=hour

#define SECS_PER_DAY 86400UL
time_t calculateDST(uint16_t year, uint8_t month, uint8_t week, uint8_t dow,  uint8_t hour){
  struct tm* ptm;
  time_t rawtime;
  uint8_t _month = month, _week = week;  //temp copies of month and week

  ptm = gmtime(0);

  if (_week == 0) {       //Last week = 0
    if (_month++ > 12) {  //for "Last", go to the next month
      _month = 1;  year++;
    }
    _week = 1;            //and treat as first week of next month, subtract 7 days later
  }
  //first day of the month, or first day of next month for "Last" rules
  ptm->tm_year = year - 1900;
  ptm->tm_mon = _month - 1;
  ptm->tm_mday = 1;
  ptm->tm_hour = hour;
  ptm->tm_min = 0;
  ptm->tm_sec = 0;
  // Do DST
  rawtime = mktime(ptm) + ((7 * (_week - 1) + (dow - ptm->tm_wday + 7) % 7) * SECS_PER_DAY);

  //back up a week if this is a "Last" rule
  if (week == 0) {
    rawtime = rawtime - (7 * SECS_PER_DAY);
  }

  return rawtime;
}

#endif /* OHS_CONF_H_ */
