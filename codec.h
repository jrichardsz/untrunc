#ifndef CODEC_HPP
#define CODEC_HPP

#include <string>
#include <vector>

#include "common.h"

class Atom;
class AVCodecContext;
class AVCodec;

class AvcConfig;

class Codec {
public:
	Codec(AVCodecContext* c);
	std::string name_;
	void parse(Atom *trak, std::vector<int> &offsets, Atom *mdat);
	bool matchSample(const uchar *start) const;
	int getSize(const uchar *start, uint maxlength, int &duration);
	//used by: mp4a
	AVCodecContext *context_;
	AVCodec *codec_;

	AvcConfig* avc_config_;

	bool was_keyframe;
	void parse(Atom* trak, const std::vector<uint>& offsets, const std::vector<int64_t>& offsets_64, Atom* mdat, bool is64);
};

#endif // CODEC_HPP
