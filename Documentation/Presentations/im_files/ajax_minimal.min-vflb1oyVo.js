define(["require","exports"],(function(e,t){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),t.post=function(e,t){var s,n,o=new XMLHttpRequest;o.open("POST",e),o.withCredentials=!0,o.setRequestHeader("X-CSRF-Token",(s="__Host-js_csrf",(n=document.cookie.match("(^|; )"+s+"=([^;]*)"))?n[2]:"")),o.send(t)}}));
//# sourceMappingURL=ajax_minimal.min.js-vfl2jb7A_.map