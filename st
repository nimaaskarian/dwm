const char *colorname[] = {

  /* 8 normal colors */
  [0] = "#090E12", /* black   */
  [1] = "#6E7174", /* red     */
  [2] = "#8D3A3C", /* green   */
  [3] = "#966C6D", /* yellow  */
  [4] = "#CC595A", /* blue    */
  [5] = "#8A7F80", /* magenta */
  [6] = "#978585", /* cyan    */
  [7] = "#c9bdbc", /* white   */

  /* 8 bright colors */
  [8]  = "#8c8483",  /* black   */
  [9]  = "#6E7174",  /* red     */
  [10] = "#8D3A3C", /* green   */
  [11] = "#966C6D", /* yellow  */
  [12] = "#CC595A", /* blue    */
  [13] = "#8A7F80", /* magenta */
  [14] = "#978585", /* cyan    */
  [15] = "#c9bdbc", /* white   */

  /* special colors */
  [256] = "#090E12", /* background */
  [257] = "#c9bdbc", /* foreground */
  [258] = "#c9bdbc",     /* cursor */
};

/* Default colors (colorname index)
 * foreground, background, cursor */
 unsigned int defaultbg = 0;
 unsigned int defaultfg = 257;
 unsigned int defaultcs = 258;
 unsigned int defaultrcs= 258;
