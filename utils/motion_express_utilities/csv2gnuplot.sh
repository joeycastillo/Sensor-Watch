#!/bin/bash
#
# This transforms a CSV file into a gnuplot file.
# use option '-h' to display a help screen for all options.
#
# FracPete

# the usage of this script
function usage()
{
   echo 
   echo "usage: ${0##*/} [-i <file>] [-o <file>] [-g <file>] [-G <file>]"
   echo "       [-O <file>] [-d <delim>] [-t] [-x] [-a] [-l] [-T]"
   echo "       [-W <width> -H <height>]] [-F <x11|png|ps>]"
   echo "       [-b <files>] [-e]"
   echo "       [-h]"
   echo
   echo "Transforms a given CSV file into a gnuplot input file. It can also"
   echo "produce a gnuplot script for plotting the data, as well as batch"
   echo "processing of several files with automatic output generation."
   echo 
   echo " -h   this help"
   echo " -i   <file>"
   echo "      the CSV file to use as input"
   echo " -o   <file>"
   echo "      the gnuplot output file, output to stdout if not provided"
   echo " -g   <file>"
   echo "      generates a gnuplot script with this name to display the data"
   echo "      it assumes that the first column is the index for the x-axis."
   echo "      In combination with '-b' this parameter is only used to indicate"
   echo "      that a script is wanted, the filename itself is ignored."
   echo " -G   <file>"
   echo "      a file containing gnuplot options, comments etc. to be added "
   echo "      before the plots"
   echo " -O   <file>"
   echo "      generates a script that outputs the plot in the format specified"
   echo "      with '-F' in a file with the given name, instead of displaying "
   echo "      it in a window"
   echo " -d   <delim>"
   echo "      the delimiter that separates the columns, default: $DELIMITER"
   echo " -t   transposes the matrix first"
   echo " -x   adds a column for the x-axis (numbers starting from 1)"
   echo " -a   generates the average of the columns"
   echo " -l   adds 'with lines' to the gnuplot script"
   echo " -T   adds a number as title to the gnuplot script"
   echo " -F   <x11|png|ps>"
   echo "      the format of the output, default: $FORMAT"
   echo " -W   <width>"
   echo "      the width of the output (if '-F png'), default: $WIDTH"
   echo " -H   <height>"
   echo "      the height of the output (if '-F png'), default: $HEIGHT"
   echo " -b   <files>"
   echo "      processes the given files in batch mode, i.e. '-i' and '-o' are"
   echo "      not necessary. the files get new extensions automatically."
   echo "      Note: use \" if you're using wildcards like '*'"
   echo " -e   generates the desired output files directly, i.e. in creates a"
   echo "      temp. gnuplot file and runs this (in combination with '-b',"
   echo "      otherwise '-g' must be given). "
   echo "      Works only if format is ps or png ('-F')."
   echo 
}

# variables
INPUT=""
OUTPUT=""
OUTPUT_PLOT=""
GNUPLOT=""
GNUPLOT_OPTIONS=""
HAS_OUTPUT="no"
HAS_GNUPLOT="no"
DELIMITER=","
TRANSPOSE="no"
XAXIS="no"
AVERAGE="no"
LINES="no"
TITLE="no"
FORMAT="x11"
WIDTH="800"
HEIGHT="600"
BATCH_FILES=""
BATCH_OPTIONS=""
EXECUTE="no"

# interprete parameters
while getopts ":hi:o:g:d:txalTF:W:H:O:b:eG:" flag
do
   case $flag in
      i) INPUT=$OPTARG
         ;;
      o) OUTPUT=$OPTARG
         HAS_OUTPUT="yes"
         ;;
      g) GNUPLOT=$OPTARG
         HAS_GNUPLOT="yes"
         ;;
      G) GNUPLOT_OPTIONS=$OPTARG
         BATCH_OPTIONS="$BATCH_OPTIONS -$flag $OPTARG"
         ;;
      d) DELIMITER=$OPTARG
         ;;
      t) TRANSPOSE="yes"
         BATCH_OPTIONS="$BATCH_OPTIONS -$flag"
         ;;
      x) XAXIS="yes"
         BATCH_OPTIONS="$BATCH_OPTIONS -$flag"
         ;;
      a) AVERAGE="yes"
         BATCH_OPTIONS="$BATCH_OPTIONS -$flag"
         ;;
      l) LINES="yes"
         BATCH_OPTIONS="$BATCH_OPTIONS -$flag"
         ;;
      T) TITLE="yes"
         BATCH_OPTIONS="$BATCH_OPTIONS -$flag"
         ;;
      O) OUTPUT_PLOT=$OPTARG
         ;;
      W) WIDTH=$OPTARG
         BATCH_OPTIONS="$BATCH_OPTIONS -$flag $OPTARG"
         ;;
      H) HEIGHT=$OPTARG
         BATCH_OPTIONS="$BATCH_OPTIONS -$flag $OPTARG"
         ;;
      F) FORMAT=$OPTARG
         BATCH_OPTIONS="$BATCH_OPTIONS -$flag $OPTARG"
         ;;
      b) BATCH_FILES=$OPTARG
         ;;
      e) EXECUTE="yes"
         BATCH_OPTIONS="$BATCH_OPTIONS -$flag"
         ;;
      h) usage
         exit 0
         ;;
      *) echo
         echo "Unknown option: '-$OPTARG'"
         echo 
         usage
         exit 1
         ;;
   esac
done

# valid combinations of parameters?
if [ ! "$BATCH_FILES" = "" ] && [ "$EXECUTE" = "yes" ] && [ "$FORMAT" = "x11" ]
then
   echo
   echo "ERROR: a format other than '$FORMAT' must be specified if '-b' and"
   echo "       '-e' are specified, e.g. 'ps'."
   echo
   usage
   exit 2
fi

# batch-mode?
if [ ! "$BATCH_FILES" = "" ]
then
   for i in $BATCH_FILES
   do
      echo "$i..."

      # build options
      OPTIONS=$BATCH_OPTIONS
      OPTIONS="$OPTIONS -i $i"
      OPTIONS="$OPTIONS -o $i.dat"
      if [ "$HAS_GNUPLOT" = "yes" ]
      then
         OPTIONS="$OPTIONS -g $i.scr"
      fi
      if [ "$FORMAT" = "png" ]
      then
         OPTIONS="$OPTIONS -O $i.png"
      fi
      if [ "$FORMAT" = "ps" ]
      then
         OPTIONS="$OPTIONS -O $i.ps"
      fi
      
      # run script
      $0 $OPTIONS
   done
   
   exit 0
fi

# test files
if [ ! "$INPUT" = "" ] && [ ! -f "$INPUT" ]
then
   INPUT=""
fi
if [ ! "$GNUPLOT_OPTIONS" = "" ] && [ ! -f "$GNUPLOT_OPTIONS" ]
then
   echo "Warning: '$GNUPLOT_OPTIONS' not found - ignored!"
   GNUPLOT_OPTIONS=""
fi

if [ "$HAS_OUTPUT" = "no" ]
then
   OUTPUT=$INPUT".tmp"
fi

# everything provided?
if [ "$INPUT" = "" ] || [ "$DELIMITER" = "" ]
then
   echo 
   echo "ERROR: not all parameters provided or incorrect!"
   echo
   usage
   exit 1
fi

if [ "$EXECUTE" = "yes" ] && [ "$HAS_GNUPLOT" = "no" ]
then
   echo
   echo "ERROR: '-g' must be specified with option '-e'!"
   echo
   usage
   exit 3
fi

if [ "$OUTPUT_PLOT" = "" ] && [ ! "$FORMAT" = "x11" ]
then
   echo "Warning: output file for format '$FORMAT' not specified, falling back to 'x11'"
   FORMAT="x11"
fi

# some variables
TMPFILE=$OUTPUT".tmp"

# init
cp $INPUT $OUTPUT

# change modifier into " "
if [ ! "$DELIMITER" = " " ]
then
   cat $OUTPUT | sed s/$DELIMITER/" "/g > $TMPFILE
   cp $TMPFILE $OUTPUT
fi

# transpose matrix?
if [ "$TRANSPOSE" = "yes" ]
then
   cat $OUTPUT | exec awk '
   NR == 1 {
           n = NF
           for (i = 1; i <= NF; i++)
                   row[i] = $i
           next
   }
   {
           if (NF > n)
                   n = NF
           for (i = 1; i <= NF; i++)
                   row[i] = row[i] " " $i
   }
   END {
           for (i = 1; i <= n; i++)
                   print row[i]
   }' > $TMPFILE
   cp $TMPFILE $OUTPUT
fi

# average columns?
if [ "$AVERAGE" = "yes" ]
then
   COLCOUNT=`head -n1 $OUTPUT | wc -w | sed s/" "*//g`
   ROWCOUNT=`cat $OUTPUT | wc -l | sed s/" "*//g`
   rm -f $TMPFILE
   
   for ((i = 1; i <= $COLCOUNT; i++))
   do
      COL=`cat $OUTPUT | cut -f$i -d" "`
      
      # average
      TMP="("`echo $COL | sed s/" "/+/g`")/$ROWCOUNT"
      if [ $i -gt 1 ]
      then
         echo -n " " >> $TMPFILE
      fi
      TMP=`echo "scale=4; $TMP" | bc -l`
      echo -n $TMP >> $TMPFILE

      # stddev
      echo -n " " >> $TMPFILE
      TMP="sqrt(($ROWCOUNT * ("`echo $COL | sed s/" "/"^2+"/g | sed s/$/"^2"/g`") - ("`echo $COL | sed s/" "/"+"/g`")^2) / ($ROWCOUNT * ($ROWCOUNT - 1)))"
      TMP=`echo "scale=4; $TMP" | bc -l`
      echo -n $TMP >> $TMPFILE
   done
   echo >> $TMPFILE
   cp $TMPFILE $OUTPUT
fi

# add x-axis?
if [ "$XAXIS" = "yes" ]
then
   cat $OUTPUT | grep -n "." | sed s/":"/" "/g > $TMPFILE
   cp $TMPFILE $OUTPUT
fi

# gnuplot script?
if [ "$HAS_GNUPLOT" = "yes" ]
then
   # data columns
   COUNT=`head -n1 $OUTPUT | wc -w | sed s/" "*//g`

   # build output/format statement
   TERM="set terminal X11"
   OUT="set output"
   if [ "$FORMAT" = "png" ]
   then
      TERM="set terminal png size $WIDTH,$HEIGHT"
      OUT="set output \"$OUTPUT_PLOT\""
   fi
   if [ "$FORMAT" = "ps" ]
   then
      TERM="set terminal postscript"
      OUT="set output \"$OUTPUT_PLOT\""
   fi
   
   # build "with" statement
   TMP=""
   WITH=""
   if [ "$LINES" = "yes" ]
   then
      TMP=$TMP" lines"
   fi
   if [ "$TITLE" = "yes" ]
   then
      TMP=$TMP" title #"
   fi
   if [ ! "$TMP" = "" ]
   then
      WITH=" with"$TMP
   fi
   
   # init
   echo "# gnuplot script for '$OUTPUT'" > $GNUPLOT
   if [ ! "$GNUPLOT_OPTIONS" = "" ]
   then
      cat $GNUPLOT_OPTIONS >> $GNUPLOT
   fi

   # the plots
   echo "set title \"$INPUT\"" >> $GNUPLOT
   echo "plot \"$OUTPUT\" using 1:2 `echo $WITH | sed s/"#"/"\'1\'"/g`" >> $GNUPLOT
   for ((i = 2; i < $COUNT; i++))
   do
      echo "replot \"$OUTPUT\" using 1:$((i+1)) `echo $WITH | sed s/"#"/"\'$i\'"/g`" >> $GNUPLOT
   done
   echo >> $GNUPLOT

   # only pause if displayed in window
   if [ "$FORMAT" = "x11" ]
   then
      echo "pause -1" >> $GNUPLOT
   else
      echo "$TERM" >> $GNUPLOT
      echo "$OUT" >> $GNUPLOT
      echo "replot" >> $GNUPLOT
   fi

   # run gnuplot
   if [ "$EXECUTE" = "yes" ]
   then
      if [ "$FORMAT" = "x11" ]
      then
         echo "Press <Return> to close window..."
      fi
      gnuplot "$GNUPLOT"
   fi
fi

# clean up
rm -f $TMPFILE
if [ "$HAS_OUTPUT" = "no" ]
then
   cat $OUTPUT
   rm -f $OUTPUT
fi