// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int beat = atoi(&fraction[0]);
    int eighth = atoi(&fraction[2]);

    if (eighth == 8)
    {
        return beat;
    }
    else if (eighth == 4)
    {
        return (beat * 2);
    }
    else if (eighth == 2)
    {
        return (beat * 4);
    }
    else if (eighth == 1)
    {
        return (beat * 8);
    }
    else
    {
        return false;
    }
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // f of A4 = 440
    // f of any other note = '440 * 2^n/12' where n is no. of semitones from A4
    // eg. f of C4 = '440 * 2^2/12' = ~494
    // eg. f of A5 = '440 * 2^12/12' = '440 * 2' = 880
    // note[0] = note
    // note[1] = accidental || octave
    // note[2] = octave (if present)

    int octave = atoi(&note[strlen(note) - 1]);
    float freq = 0.0;

    if (note[0] == 'A')
    {
        freq = 440.0;
    }
    else if (note[0] == 'B')
    {
        freq = 440.0 * (pow(2.0, (2.0 / 12.0)));
    }
    else if (note[0] == 'C')
    {
        freq = 440.0 / (pow(2.0, (9.0 / 12.0)));
    }
    else if (note[0] == 'D')
    {
        freq = 440.0 / (pow(2.0, (7.0 / 12.0)));
    }
    else if (note[0] == 'E')
    {
        freq = 440.0 / (pow(2.0, (5.0 / 12.0)));
    }
    else if (note[0] == 'F')
    {
        freq = 440.0 / (pow(2.0, (4.0 / 12.0)));
    }
    else if (note[0] == 'G')
    {
        freq = 440.0 / (pow(2.0, (2.0 / 12.0)));
    }


    // Loop to adjust for octave

    if (octave > 4)
    {
        for (int i = 0; i < octave - 4; i++)
        {
            freq *= 2;
        }
    }
    else if (octave < 4)
    {
        for (int i = 0; i < 4 - octave; i++)
        {
            freq /= 2;
        }
    }


    // Adjust if # || b

    if (note[1] == '#')
    {
        freq *= (pow(2.0, (1.0 / 12.0)));
    }
    else if (note[1] == 'b')
    {
        freq /= (pow(2.0, (1.0 / 12.0)));
    }


    // Return freq as rounded int

    int f = round(freq);
    return f;

}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
