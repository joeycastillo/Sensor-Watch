# Astrolib

This is a relatively straightforward C port of Greg Miller's [JavaScript astro library](https://github.com/gmiller123456/astrogreg), done by Joey Castillo, for the Sensor Watch Astronomy watch face.

He released his work into the public domain and so I release this into the public domain as well.

I have tested the output of this library against [NASA's Horizons system](https://ssd.jpl.nasa.gov/horizons/app.html#/) and found the results to match (within reason, as we're using a truncated version of VSOP87). Moon calculations still seem a bit iffy, but it doesn't surprise me seeing as there are three calculations involved and the error could stack up.

THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
