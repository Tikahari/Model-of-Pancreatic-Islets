define(["require","exports","tslib","react","classnames","modules/core/i18n","dig-components/buttons","dig-components/typography","modules/clean/react/image"],(function(e,a,t,r,d,o,l,i,c){"use strict";Object.defineProperty(a,"__esModule",{value:!0}),r=t.__importDefault(r),d=t.__importDefault(d),a.ModuleCardBodyContainer=function(e){var a,o=e.children,l=e.className,i=e.cardBodyAccessibilityProps,c=d.default(((a={"module-card__body":!0})[l||""]=!!l,a));return r.default.createElement("div",t.__assign({className:c},i),o)},a.ModuleCardBodyContainer.displayName="ModuleCardBodyContainer",a.ModuleCardImage=function(e){var a=e.src,t=e.srcHiRes,d=e.alt;return r.default.createElement(c.Image,{className:"module-card__image",alt:d,src:a,srcHiRes:t})},a.ModuleCardImage.displayName="ModuleCardImage",a.ModuleCardDescription=function(e){var a=e.description;return r.default.createElement(i.Text,{className:"module-card__description",tagName:"p",color:"faint"},a)},a.ModuleCardDescription.displayName="ModuleCardDescription",a.ModuleCardButtonGroup=function(e){var a=e.hasPrimaryCtaStyle,t=e.onCtaClick,d=e.ctaText,i=e.onSkipClick,c=e.primaryButton,n=e.disabled,s=r.default.createElement(l.Button,{variant:a?"primary":"opacity",onClick:t,disabled:n,className:"module-card__button-group__primary-cta"},d);return r.default.createElement("div",{className:"module-card__button-group"},c||s,i&&r.default.createElement(l.Button,{variant:"transparent",onClick:i,disabled:n,className:"module-card__button-group__skip-cta"},o.intl.formatMessage({id:"2iucH+",defaultMessage:"Skip"})))},a.ModuleCardButtonGroup.displayName="ModuleCardButtonGroup",a.ModuleCardBody=function(e){var t=e.description,d=e.imageUrl,o=e.imageUrlHiRes,l=e.imageAlt,i=e.onCtaClick,c=e.onSkipClick,n=e.ctaText,s=e.hasPrimaryCtaStyle,u=e.cardBodyAccessibilityProps,m=e.className;return r.default.createElement(a.ModuleCardBodyContainer,{cardBodyAccessibilityProps:u,className:m},d&&r.default.createElement(a.ModuleCardImage,{alt:l,src:d,srcHiRes:o}),t&&r.default.createElement(a.ModuleCardDescription,{description:t}),i&&r.default.createElement(a.ModuleCardButtonGroup,{hasPrimaryCtaStyle:s,onCtaClick:i,ctaText:n,onSkipClick:c}))},a.ModuleCardBody.displayName="ModuleCardBody"}));
//# sourceMappingURL=card_components.min.js-vflX89tIk.map