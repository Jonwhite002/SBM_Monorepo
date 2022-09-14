/* Generated by DBCC, see <https://github.com/howerj/dbcc> */
#include "sbm_network_definition.h"
#include <inttypes.h>
#include <assert.h>

#define UNUSED(X) ((void)(X))

static inline uint64_t reverse_byte_order(uint64_t x) {
	x = (x & 0x00000000FFFFFFFF) << 32 | (x & 0xFFFFFFFF00000000) >> 32;
	x = (x & 0x0000FFFF0000FFFF) << 16 | (x & 0xFFFF0000FFFF0000) >> 16;
	x = (x & 0x00FF00FF00FF00FF) << 8  | (x & 0xFF00FF00FF00FF00) >> 8;
	return x;
}

static inline int print_helper(int r, int print_return_value) {
	return ((r >= 0) && (print_return_value >= 0)) ? r + print_return_value : -1;
}

static int pack_can_0x100_IMU(can_obj_sbm_network_definition_h_t *o, uint64_t *data) {
	assert(o);
	assert(data);
	register uint64_t x;
	register uint64_t i = 0;
	/* Body_Roll_deg: start-bit 0, length 16, endianess intel, scaling 0.1, offset 0 */
	x = ((uint16_t)(o->can_0x100_IMU.Body_Roll_deg)) & 0xffff;
	i |= x;
	/* Body_Pitch_deg: start-bit 16, length 16, endianess intel, scaling 0.1, offset 0 */
	x = ((uint16_t)(o->can_0x100_IMU.Body_Pitch_deg)) & 0xffff;
	x <<= 16; 
	i |= x;
	/* Body_Yaw_deg: start-bit 32, length 16, endianess intel, scaling 0.1, offset 0 */
	x = ((uint16_t)(o->can_0x100_IMU.Body_Yaw_deg)) & 0xffff;
	x <<= 32; 
	i |= x;
	*data = (i);
	o->can_0x100_IMU_tx = 1;
	return 0;
}

static int unpack_can_0x100_IMU(can_obj_sbm_network_definition_h_t *o, uint64_t data, uint8_t dlc, dbcc_time_stamp_t time_stamp) {
	assert(o);
	assert(dlc <= 8);
	register uint64_t x;
	register uint64_t i = (data);
	if (dlc < 8)
		return -1;
	/* Body_Roll_deg: start-bit 0, length 16, endianess intel, scaling 0.1, offset 0 */
	x = i & 0xffff;
	o->can_0x100_IMU.Body_Roll_deg = x;
	/* Body_Pitch_deg: start-bit 16, length 16, endianess intel, scaling 0.1, offset 0 */
	x = (i >> 16) & 0xffff;
	o->can_0x100_IMU.Body_Pitch_deg = x;
	/* Body_Yaw_deg: start-bit 32, length 16, endianess intel, scaling 0.1, offset 0 */
	x = (i >> 32) & 0xffff;
	o->can_0x100_IMU.Body_Yaw_deg = x;
	o->can_0x100_IMU_rx = 1;
	o->can_0x100_IMU_time_stamp_rx = time_stamp;
	return 0;
}

int decode_can_0x100_Body_Roll_deg(const can_obj_sbm_network_definition_h_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->can_0x100_IMU.Body_Roll_deg);
	rval *= 0.1;
	if (rval <= 359) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x100_Body_Roll_deg(can_obj_sbm_network_definition_h_t *o, double in) {
	assert(o);
	o->can_0x100_IMU.Body_Roll_deg = 0;
	if (in > 359)
		return -1;
	in *= 10;
	o->can_0x100_IMU.Body_Roll_deg = in;
	return 0;
}

int decode_can_0x100_Body_Pitch_deg(const can_obj_sbm_network_definition_h_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->can_0x100_IMU.Body_Pitch_deg);
	rval *= 0.1;
	if (rval <= 359) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x100_Body_Pitch_deg(can_obj_sbm_network_definition_h_t *o, double in) {
	assert(o);
	o->can_0x100_IMU.Body_Pitch_deg = 0;
	if (in > 359)
		return -1;
	in *= 10;
	o->can_0x100_IMU.Body_Pitch_deg = in;
	return 0;
}

int decode_can_0x100_Body_Yaw_deg(const can_obj_sbm_network_definition_h_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->can_0x100_IMU.Body_Yaw_deg);
	rval *= 0.1;
	if (rval <= 359) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x100_Body_Yaw_deg(can_obj_sbm_network_definition_h_t *o, double in) {
	assert(o);
	o->can_0x100_IMU.Body_Yaw_deg = 0;
	if (in > 359)
		return -1;
	in *= 10;
	o->can_0x100_IMU.Body_Yaw_deg = in;
	return 0;
}

int print_can_0x100_IMU(const can_obj_sbm_network_definition_h_t *o, FILE *output) {
	assert(o);
	assert(output);
	int r = 0;
	r = print_helper(r, fprintf(output, "Body_Roll_deg = (wire: %.0f)\n", (double)(o->can_0x100_IMU.Body_Roll_deg)));
	r = print_helper(r, fprintf(output, "Body_Pitch_deg = (wire: %.0f)\n", (double)(o->can_0x100_IMU.Body_Pitch_deg)));
	r = print_helper(r, fprintf(output, "Body_Yaw_deg = (wire: %.0f)\n", (double)(o->can_0x100_IMU.Body_Yaw_deg)));
	return r;
}

static int pack_can_0x101_GPS(can_obj_sbm_network_definition_h_t *o, uint64_t *data) {
	assert(o);
	assert(data);
	register uint64_t x;
	register uint64_t i = 0;
	/* Body_Speed_mps: start-bit 0, length 8, endianess intel, scaling 0.1, offset 0 */
	x = ((uint8_t)(o->can_0x101_GPS.Body_Speed_mps)) & 0xff;
	i |= x;
	*data = (i);
	o->can_0x101_GPS_tx = 1;
	return 0;
}

static int unpack_can_0x101_GPS(can_obj_sbm_network_definition_h_t *o, uint64_t data, uint8_t dlc, dbcc_time_stamp_t time_stamp) {
	assert(o);
	assert(dlc <= 8);
	register uint64_t x;
	register uint64_t i = (data);
	if (dlc < 8)
		return -1;
	/* Body_Speed_mps: start-bit 0, length 8, endianess intel, scaling 0.1, offset 0 */
	x = i & 0xff;
	o->can_0x101_GPS.Body_Speed_mps = x;
	o->can_0x101_GPS_rx = 1;
	o->can_0x101_GPS_time_stamp_rx = time_stamp;
	return 0;
}

int decode_can_0x101_Body_Speed_mps(const can_obj_sbm_network_definition_h_t *o, double *out) {
	assert(o);
	assert(out);
	double rval = (double)(o->can_0x101_GPS.Body_Speed_mps);
	rval *= 0.1;
	if (rval <= 25.5) {
		*out = rval;
		return 0;
	} else {
		*out = (double)0;
		return -1;
	}
}

int encode_can_0x101_Body_Speed_mps(can_obj_sbm_network_definition_h_t *o, double in) {
	assert(o);
	o->can_0x101_GPS.Body_Speed_mps = 0;
	if (in > 25.5)
		return -1;
	in *= 10;
	o->can_0x101_GPS.Body_Speed_mps = in;
	return 0;
}

int print_can_0x101_GPS(const can_obj_sbm_network_definition_h_t *o, FILE *output) {
	assert(o);
	assert(output);
	int r = 0;
	r = print_helper(r, fprintf(output, "Body_Speed_mps = (wire: %.0f)\n", (double)(o->can_0x101_GPS.Body_Speed_mps)));
	return r;
}

int unpack_message(can_obj_sbm_network_definition_h_t *o, const unsigned long id, uint64_t data, uint8_t dlc, dbcc_time_stamp_t time_stamp) {
	assert(o);
	assert(id < (1ul << 29)); /* 29-bit CAN ID is largest possible */
	assert(dlc <= 8);         /* Maximum of 8 bytes in a CAN packet */
	switch (id) {
	case 0x100: return unpack_can_0x100_IMU(o, data, dlc, time_stamp);
	case 0x101: return unpack_can_0x101_GPS(o, data, dlc, time_stamp);
	default: break; 
	}
	return -1; 
}

int pack_message(can_obj_sbm_network_definition_h_t *o, const unsigned long id, uint64_t *data) {
	assert(o);
	assert(id < (1ul << 29)); /* 29-bit CAN ID is largest possible */
	switch (id) {
	case 0x100: return pack_can_0x100_IMU(o, data);
	case 0x101: return pack_can_0x101_GPS(o, data);
	default: break; 
	}
	return -1; 
}

int print_message(const can_obj_sbm_network_definition_h_t *o, const unsigned long id, FILE *output) {
	assert(o);
	assert(id < (1ul << 29)); /* 29-bit CAN ID is largest possible */
	assert(output);
	switch (id) {
	case 0x100: return print_can_0x100_IMU(o, output);
	case 0x101: return print_can_0x101_GPS(o, output);
	default: break; 
	}
	return -1; 
}
