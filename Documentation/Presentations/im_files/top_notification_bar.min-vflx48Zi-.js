define(["require","exports","tslib","modules/clean/ajax_minimal"],(function(e,t,o,i){"use strict";Object.defineProperty(t,"__esModule",{value:!0}),i=o.__importStar(i);var n=["top-notification-bar","has-top-notification"];function a(e){var t;void 0===e&&(e=[]),(t=document.body.classList).add.apply(t,o.__spreadArrays(n,e))}function s(e,t){var o=document.querySelector(e);o&&o.classList.remove(t)}function r(e){var t;void 0===e&&(e=[]);var i=document.getElementById("top-notification-bar-container");i.parentNode.removeChild(i),(t=document.body.classList).remove.apply(t,o.__spreadArrays(n,e)),s(".maestro .has-top-notification","has-top-notification"),s(".maestro #notify-wrapper.with-top-notification","with-top-notification"),s(".IndexRebrandPage","top-notification-bar"),s(".IndexZeusRebrandPage","top-notification-bar")}t.removeClassIfElmExists=s,t.showEUCookieNotificationBar=function(){a(["has-eu-cookie-bar"]),document.querySelector(".eu-bar-dismiss").addEventListener("click",(function(e){e.preventDefault(),r(["has-eu-cookie-bar"]),i.post("/dismiss_eu_cookie_notification","")}))},t.showSuperInactiveRecoverBar=function(){a(),document.getElementById("super-inactive-recover-bar-dismiss").addEventListener("click",(function(e){e.preventDefault(),r(),i.post("/dismiss_super_inactive_recover_bar","")}))},t.showUnsupportedBrowserBar=function(){a(),document.getElementById("unsupported-browser-dismiss").addEventListener("click",(function(e){e.preventDefault(),r(),i.post("/dismiss_browser_msg","")}))},t.showBetaLocaleNotificationBar=function(e){a(),document.querySelector(".beta-locale-dismiss").addEventListener("click",(function(t){t.preventDefault(),r(),i.post("/dismiss_beta_locale_notification","source="+e)}))}}));
//# sourceMappingURL=top_notification_bar.min.js-vfl6H2daH.map