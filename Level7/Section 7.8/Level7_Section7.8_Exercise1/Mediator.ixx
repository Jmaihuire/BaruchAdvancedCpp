import Input;
import Processing;
import Output;

// The mediator is bascially a combiner and incorporates all the other modules together to make an application
// Very simplified because I ran out of time 

export module Mediator;

export void run() {
	double in_ = in(); //get double from input module
	S s1;
	out(s1.processing(in_, in_ + 1)); //print the output of the processor
};