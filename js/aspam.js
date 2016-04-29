/*
 * jQuery Aspam - Spam protection plugin
 *
 * Copyright 2015-2016, Mirosław Sztorc
 * http://sztorc.com
 *
 * Licensed under the MIT license:
 * http://www.opensource.org/licenses/MIT
 */
(function($) {

    $.widget("spam.aspam", {
        // Default options.

        r: {},
        _i: 0,
        _timer: {},
        selfie: null,
        letter: null,
        se: null,
        cstring: '',
        chash: '',
        options: {
            width: 50,
            height: 50,
            numChars: 6,
            transformTime: 1000,
            showTime: 1500,
            backgroundColor: '#5BAE09',
            borderColor: '#4F9607',
            borderWidth: 1,
            charColor: '#5BAE09',
            fillOpacity: 0.8,
            charStrokeColor: '#5BAE09',
            charStrokeWidth: 2,
            charWidthScale: 0.25,
            charHeightScale: 0.25,
            padlockOpacity: 0.3,
            padlockFillColor: '#000000',
            paddingLeft: 'auto',
            paddingTop: 'auto',
            symbols: 'lowercase|uppercase|digits',
            encryption: false, // If true require JSEncrypt
            publicKey: ''

        },
        _create: function() {

/*            if (this.options.paddingLeft == 'auto') this.options.paddingLeft = Math.round((this.options.width - (75 * this.options.charWidthScale)));
            if (this.options.paddingTop == 'auto') this.options.paddingTop = Math.round((this.options.height - (75 * this.options.charHeightScale)));

            this.options.paddingLeft = (this.options.paddingLeft >= 0) ? this.options.paddingLeft : 0; 
            this.options.paddingTop = (this.options.paddingTop >= 0) ? this.options.paddingTop : 0;

            console.log('this.options.paddingLeft: ' + this.options.paddingLeft);
            console.log('this.options.paddingTop: ' + this.options.paddingTop);*/

            //padlock
            var img = '<div id="aspam-padlock" style="width:' + this.options.width + 'px; height:' + this.options.height + 'px;"></div>';

            selfie = this;

            this.r = Raphael("aspam-holder", this.options.width, this.options.height);
            // selfie.letter = this.r.path("M0,0L0,0z").attr({fill: "#5BAE09", stroke: "#fff", "fill-opacity": 1, "stroke-width": 1, "stroke-linecap": "round", translation: "100 100"});
            selfie.letter = selfie.r.path("M0,0z")
                .attr({
                    fill: this.options.charColor,
                    stroke: this.options.charStrokeColor,
                    "fill-opacity": this.options.fillOpacity,
                    "stroke-width": this.options.charStrokeWidth,
                    "stroke-linecap": "round"
                })
                .translate(0,0);
 
            this.element.width(this.options.width);

            selfie.se = this.element.find('#aspam-padlock')
                .addClass("spam")
                .width(this.options.width)
                .height(this.options.height)
                .css({
                    borderColor: this.options.borderColor,
                    borderType: 'solid',
                    borderWidth: this.options.borderWidth,
                    background: this.options.backgroundColor,
                    textAlign: 'center',
                    verticalAlign: 'middle',
                    display: 'table-cell',
                    position: 'absolute',
                    cursor: 'pointer',
                    top: 0,
                    left: 0,
                    zIndex: 10000
                    /* lineHeight: this.options.height + 'px' */
                })
                .html(img).fadeTo('fast', 1)
                .click(function() {

                    var left = selfie.se.offset().left;
                    // se.css({left:left}).animate({"left":"0px"}, "slow");

                    selfie.se.fadeOut('normal');

                    selfie.run();
                    jQuery("input[name=captcha_response]").focus();

                });

            var pscale = (this.options.width / 500);
            var padlockStr = "M 97.357129,434.70306 C 99.380791,446.80968 109.88977,456.00501 122.56443,456.00501 L 383.8685,456.00501 C 396.54315,456.00501 407.05213,446.80968 409.0758,434.70306 L 97.357129,434.70306 z M 122.56443,235.88479 C 108.43415,235.88479 97.002058,247.31683 97.002058,261.44713 L 97.002058,416.95142 L 409.43088,416.95142 L 409.43088,261.44713 C 409.43088,247.31683 397.99878,235.88479 383.8685,235.88479 L 368.28255,235.88479 C 368.49559,232.93799 368.6021,169.63567 368.6021,166.65339 C 368.6021,102.92501 316.94484,51.267752 253.21646,51.267752 C 189.4881,51.267752 137.83083,102.92501 137.83083,166.65339 C 137.83083,169.63567 137.93734,232.93799 138.15039,235.88479 L 122.56443,235.88479 z M 298.51862,235.88479 L 207.91431,235.88479 C 207.34625,233.009 207.0622,169.70666 207.0622,166.65339 C 207.0622,141.16205 227.72513,120.49917 253.21646,120.49917 C 278.70782,120.49917 299.37074,141.16205 299.37074,166.65339 C 299.37074,169.70666 299.0867,233.009 298.51862,235.88479 z";
            ppaper = Raphael("aspam-padlock", this.options.width, this.options.height);
            var padlock = ppaper.path(padlockStr).attr({
                "transform": "s0.5,0.5t-100,-100",
                "fill-opacity": this.options.padlockOpacity,
                "type": "path",
                "fill-rule": "evenodd",
                "fill": this.options.padlockFillColor,
                "stroke": "none"
            });
            padlock.transform('S' + pscale + ',' + pscale + ',0,0');

        },
        _charRand: function() {

            var lchars = 'abcdefghijklmnpqrstuvwxyz'; // o is omitted, because is similar to 0
            var uchars = 'ABCDEFGHIJKLMPQRSTUVWXYZ'; // O is omitted, because is similar to 0
            var digits = '123456789'; // 0 is omittet, because is similar to O

            var symbols = '';

            if (this.options.symbols.search(/lowercase/i)) symbols += lchars;
            if (this.options.symbols.search(/uppercase/i)) symbols += uchars;
            if (this.options.symbols.search(/digits/i)) symbols += digits;

            key = symbols.charAt(Math.floor(Math.random() * symbols.length));

            if (selfie.cstring.substring(selfie.cstring.length - 1) != key) {

                selfie.chash = (key.charCodeAt(0) % 2 == 0) ? CryptoJS.MD5(selfie.chash + key + key.charCodeAt(0)).toString() : CryptoJS.MD5(selfie.chash + key.charCodeAt(0)).toString();

                selfie.cstring += key;

                if (this.options.encryption) {

                    var encrypt = new JSEncrypt();
                    encrypt.setPublicKey(this.options.publicKey);
                    var encrypted = encrypt.encrypt(selfie.chash);

                    jQuery("input[name=aspam_chash]").val(encrypted);

                } else jQuery("input[name=aspam_chash]").val(selfie.chash);

                return key;

            } else selfie._charRand();


        },
        wait: function() {

            window.setTimeout(function() {
                selfie.showNext();
            }, this.options.showTime);

        },
        run: function() {

            selfie.cstring = '';
            selfie.chash = '';
            this._i = 0;

            this._timer = window.setInterval(function() {
                selfie.wait();
            }, this.options.showTime);

        },
        stop: function() {
            window.clearInterval(this._timer);
        },
        showNext: function() {

            if (this._i < this.options.numChars) {

                var pos = [0, 0];

                var key = this._charRand();


                if (key && key in helvetica) {


                    if (this.options.paddingLeft == 'auto') this.options.paddingLeft = Math.round((this.options.width-(110*this.options.charWidthScale))/2);
                    if (this.options.paddingTop == 'auto') this.options.paddingTop = Math.round((this.options.height-(110*this.options.charHeightScale))/2);

                    var anim = Raphael.animation({
                        transform: "s" + this.options.charWidthScale + "," + this.options.charHeightScale + ","+this.options.paddingLeft+","+this.options.paddingTop,
                        path: helvetica[key],
                    }, this.options.transformTime);

                    selfie.letter.animate(anim);

                }

                this._i++;


            } else {

                selfie.chash = '';
                selfie.se.fadeIn('normal');
                selfie.letter.animate({
                    path: 'M,0,0'
                }, 1000);
                this.stop();
            }

        }
        
    });

})(jQuery);